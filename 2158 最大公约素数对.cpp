#include <bits/stdc++.h>
using namespace std;

const int M = 3e6 + 5;
const int SZ = 1e5 + 5;
int phi[M], pr[M / 10], pc;
bool vis[M];
long long sp[M];
int m;
long long v[SZ], g[SZ];
long long n, sq;
unordered_map<long long, long long> mp;

void build() {
    phi[1] = 1;
    for (int i = 2; i < M; i++) {
        if (!vis[i]) {
            pr[++pc] = i, phi[i] = i - 1;
        }
        for (int j = 1; j <= pc && 1LL * i * pr[j] < M; j++) {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0) {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
            phi[i * pr[j]] = phi[i] * (pr[j] - 1);
        }
    }
    for (int i = 1; i < M; i++) {
        sp[i] = sp[i - 1] + phi[i];
    }
}

long long S(long long x) {
    if (x < M) {
        return sp[x];
    }
    if (mp.count(x)) {
        return mp[x];
    }
    long long r = x * (x + 1) / 2;
    for (long long l = 2, q; l <= x; l = q + 1) {
        q = x / (x / l);
        r -= (q - l + 1) * S(x / l);
    }
    mp[x] = r;
    return r;
}

int id(long long x) {
    if (x <= sq) {
        return m - (int)x + 1;
    }
    return (int)(n / x);
}

long long cntp(long long x) {
    if (x < 2) {
        return 0;
    }
    return g[id(x)];
}

signed main() {
    if (freopen("cyj.in", "r", stdin) == NULL) {
        freopen("cyj00.in", "r", stdin);
        freopen("cyj00.out", "w", stdout);
    }
    scanf("%lld", &n);
    if (n < 1) {
        printf("0\n");
        return 0;
    }
    build();
    sq = (long long)sqrt((long double)n);
    for (long long l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        v[++m] = n / l;
    }
    for (int i = 1; i <= m; i++) {
        g[i] = v[i] - 1;
    }
    for (long long p = 2; p <= sq; p++) {
        if (g[id(p)] == g[id(p - 1)]) {
            continue;
        }
        for (int i = 1; i <= m && v[i] >= p * p; i++) {
            g[i] -= g[id(v[i] / p)] - g[id(p - 1)];
        }
    }
    long long ans = 0;
    for (long long l = 1, r; l <= n; l = r + 1) {
        long long q = n / l;
        r = n / q;
        long long c = cntp(r) - cntp(l - 1);
        if (c > 0) {
            ans += (4 * S(q) - 2) * c;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
