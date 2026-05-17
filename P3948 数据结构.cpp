#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 200000 + 5;
struct node {
    ll val, pos;
} c[M * 4];
ll n, k, opt, mod, minn, maxn, cnt, lazy[M * 4], ans, sum[M * 4];
void build(int h, int s, int t) {
    if (s == t) {
        c[h].pos = ++cnt;
        return;
    }
    ll mid = s + (t - s) / 2;
    build(h << 1, s, mid);
    build(h << 1 | 1, mid + 1, t);
}
int read() {
    ll re = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -f;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        re = re * 10 + ch - '0';
        ch = getchar();
    }
    return re * f;
}
void Push_down(ll h, ll s, ll t, ll vall) {
    lazy[h] += vall;
    c[h].val += (t - s + 1) * vall;
}
void gx(ll h, ll s, ll t, ll L, ll R, ll vall) {
    ll mid = s + (t - s) / 2;
    if (L <= s && t <= R) {
        c[h].val += (t - s + 1) * vall;
        lazy[h] += vall;
    } else {
        if (lazy[h]) {
            Push_down(h << 1, s, mid, lazy[h]);
            Push_down(h << 1 | 1, mid + 1, t, lazy[h]);
            lazy[h] = 0;
        }
        if (L <= mid)
            gx(h << 1, s, mid, L, R, vall);
        if (mid < R)
            gx(h << 1 | 1, mid + 1, t, L, R, vall);
        c[h].val = c[h << 1].val + c[h << 1 | 1].val;
    }
}
void cx(ll h, ll s, ll t, ll L, ll R) {
    ll mid = s + (t - s) / 2;
    if (s == t) {
        if (c[h].pos * c[h].val % mod >= minn && c[h].pos * c[h].val % mod <= maxn)
            ans++;
    } else {
        if (lazy[h]) {
            Push_down(h << 1, s, mid, lazy[h]);
            Push_down(h << 1 | 1, mid + 1, t, lazy[h]);
            lazy[h] = 0;
        }
        if (L <= mid)
            cx(h << 1, s, mid, L, R);
        if (mid < R)
            cx(h << 1 | 1, mid + 1, t, L, R);
    }
}
void qzh(int h, int s, int t) {
    ll mid = s + (t - s) / 2;
    if (s == t) {
        cnt++;
        if (c[h].pos * c[h].val % mod >= minn && c[h].pos * c[h].val % mod <= maxn)
            sum[cnt] = sum[cnt - 1] + 1;
        else
            sum[cnt] = sum[cnt - 1];
        return;
    } else {
        if (lazy[h]) {
            Push_down(h << 1, s, mid, lazy[h]);
            Push_down(h << 1 | 1, mid + 1, t, lazy[h]);
            lazy[h] = 0;
        }
        qzh(h << 1, s, mid);
        qzh(h << 1 | 1, mid + 1, t);
    }
}
int main() {
    n = read();
    opt = read();
    mod = read();
    minn = read();
    maxn = read();
    build(1, 1, n);
    for (ll i = 1; i <= opt; i++) {
        char f;
        ll x, y, z;
        cin >> f;
        cin >> x >> y;
        if (f == 'A') {
            cin >> z;
            gx(1, 1, n, x, y, z);
        }
        if (f == 'Q') {
            ans = 0;
            cx(1, 1, n, x, y);
            cout << ans << endl;
        }
    }
    k = read();
    cnt = 0;
    qzh(1, 1, n);
    for (ll i = 1; i <= k; i++) {
        ll u, v;
        u = read();
        v = read();
        cout << sum[v] - sum[u - 1] << endl;
    }
    return 0;
}
