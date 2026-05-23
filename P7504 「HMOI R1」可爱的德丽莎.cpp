#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
#define ll long long
#define ri int
#define pii pair<int, int>
const ll mod = 998244353, inv = mod + 1 >> 1, inv3 = 332748118;
ll add(ll x, ll y) { return (x += y) < mod ? x : x - mod; }
ll dec(ll x, ll y) { return (x -= y) < 0 ? x + mod : x; }
ll ksm(ll d, ll t) {
    ll res = 1;
    for (; t; t >>= 1, d = d * d % mod)
        if (t & 1)
            res = res * d % mod;
    return res;
}
const int MAXN = 1e5 + 7;
int totcnt = 0;
namespace Getphi {
const int MAXM = 1e7 + 7;
int val[MAXM], as[MAXM], nxt[MAXM], mapcnt;
struct hmap {
    static const int P = 10007;
    int hed[P];
    bool count(int x) {
        int c = hed[x % P];
        while (c) {
            if (val[c] == x)
                return 1;
            c = nxt[c];
        }
        return 0;
    }
    int &operator[](int x) {
        int c = hed[x % P];
        while (c) {
            if (val[c] == x)
                return as[c];
            c = nxt[c];
        }
        ++mapcnt;
        val[mapcnt] = x;
        nxt[mapcnt] = hed[x % P];
        hed[x % P] = mapcnt;
        return as[mapcnt];
    }
    int size() { return mapcnt; }
} S[4650];
int n, p1[MAXN], p2[MAXN], cnt, N, flag[MAXN], prim[MAXN], w[MAXN];
int pos(int x) {
    if (1ll * x * x <= n)
        return p1[x];
    else
        return p2[n / x];
}
ll g1[MAXN], g2[MAXN];
ll C2(ll x) { return x * (x + 1) / 2 % mod; }
ll C3(ll x) { return C2(x) * (x + x + 1) % mod * inv3 % mod; }
void init(int _n) {
    n = _n;
    N = sqrt(n);
    for (ri i = 2; i <= N; ++i) {
        if (!flag[i])
            prim[++prim[0]] = i;
        for (ri j = 1; j <= prim[0] && i * prim[j] <= N; ++j) {
            flag[i * prim[j]] = 1;
            if (i % prim[j] == 0)
                break;
        }
    }
    for (ri l = 1, r; l <= n; l = r + 1) {
        int cur = n / l;
        r = n / cur;
        w[++cnt] = cur;
        if (1ll * cur * cur <= n)
            p1[cur] = cnt;
        else
            p2[n / cur] = cnt;
        g1[cnt] = C2(cur) - 1;
        g2[cnt] = C3(cur) - 1;
    }
    for (ri t = 1; t <= prim[0]; ++t) {
        for (ri i = 1; i <= cnt && w[i] >= prim[t] * prim[t]; ++i) {
            int nxtl = pos(w[i] / prim[t]), nxtr = (t == 1 ? 0 : pos(prim[t - 1]));
            g1[i] = dec(g1[i], dec(g1[nxtl], g1[nxtr]) * prim[t] % mod);
            g2[i] = dec(g2[i], dec(g2[nxtl], g2[nxtr]) * prim[t] % mod * prim[t] % mod);
        }
    }
}
ll getS(int n, int cur) {
    int P = pos(n);
    if (cur && prim[cur] >= n)
        return 0;
    if (S[cur].count(P))
        return S[cur][P];
    int r = pos(n), l = cur == 0 ? 0 : pos(prim[cur]);
    ll ans = dec(dec(g2[r], g2[l]), dec(g1[r], g1[l]));
    for (ri i = cur + 1; i <= prim[0] && 1ll * prim[i] * prim[i] <= n; ++i) {
        for (ll e = 1, v = prim[i], W = 1; v <= n; ++e, v *= prim[i], W *= prim[i]) {
            ll res = getS(n / v, i);
            if (e != 1)
                ++res;
            res = res * v % mod * W % mod * (prim[i] - 1) % mod;
            ans = add(ans, res);
        }
    }
    return S[cur][P] = ans;
}
ll getphi(ll x) {
    ll now = getS(x, 0) + 1;
    return now;
}
} 
ll ans;
ll sta[64], top;
int f[64][MAXN];
ll g(ll n, int cur) {
    if (n == 0)
        return 0;
    int P = Getphi::pos(n);
    if (~f[cur][P])
        return f[cur][P];
    if (cur == 0)
        return f[cur][P] = Getphi::getphi(n);
    return f[cur][P] = add((sta[cur] - 1) * g(n, cur - 1) % mod, sta[cur] * g(n / sta[cur], cur) % mod);
}
ll S(ll n, ll k) {
    ll res = 1;
    for (ri t = 1; t * t <= k; ++t) {
        if (k % t)
            continue;
        if (t <= n) {
            ll x = t;
            int now = 1;
            top = 0;
            for (ll i = 2; i * i <= t && i <= x; ++i) {
                int cnt = 0;
                while (x % i == 0)
                    ++cnt, x /= i;
                if (cnt > 1)
                    goto Nex;
                if (cnt)
                    sta[++top] = i, now = -now;
            }
            if (x > 1)
                now = -now, sta[++top] = x;
            for (ri i = 0; i <= top; ++i)
                for (ri j = 0; j <= Getphi::cnt; ++j)
                    f[i][j] = -1;
            if (now == 1)
                res = add(res, g(n / t, top) * t % mod);
            if (now == -1)
                res = dec(res, g(n / t, top) * t % mod);
        Nex:;
        }
        if (t * t != k && k / t <= n) {
            ll x = (k / t);
            int now = 1;
            top = 0;
            for (ll i = 2; i * i <= (k / t) && i <= x; ++i) {
                int cnt = 0;
                while (x % i == 0)
                    ++cnt, x /= i;
                if (cnt > 1)
                    goto Next;
                if (cnt)
                    sta[++top] = i, now = -now;
            }
            if (x > 1)
                now = -now, sta[++top] = x;
            for (ri i = 0; i <= top; ++i)
                for (ri j = 0; j <= Getphi::cnt; ++j)
                    f[i][j] = -1;
            if (now == 1)
                res = add(res, g(n / (k / t), top) * (k / t) % mod);
            if (now == -1)
                res = dec(res, g(n / (k / t), top) * (k / t) % mod);
        Next:;
        }
    }
    return res * inv % mod;
}
ll n, k1, k2;
int main() {
    
    
    scanf("%lld%lld%lld", &n, &k1, &k2);
    Getphi::init(n);
    printf("%lld\n", S(n, k1) * S(n, k2) % mod);
}