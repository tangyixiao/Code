#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
const int N = 2e5 + 5, M = 1e6 + 5, mod = 998244353;
int a[N], b[N], p[M], pr[M], f[M], c[M], s[M], ans[M], cnt[M];
int n, q, g, A, B, pc, x, y, e, t, k, w;
long long h;

inline int gcd(int x, int y) {
    for (; y;) { x %= y, swap(x, y); }
    return x;
}

inline void init(int lim) {
    for (int i = 2; i <= lim; i++) {
        if (!p[i]) { p[i] = i, pr[++pc] = i; }
        for (int j = 1; j <= pc && pr[j] <= p[i] && 1LL * i * pr[j] <= lim; j++) { p[i * pr[j]] = pr[j]; }
    }
    f[1] = 1;
    for (int i = 2; i <= lim; i++) {
        x = i, e = 0;
        for (; x % p[i] == 0;) { x /= p[i], e++; }
        f[i] = 1LL * f[x] * ((e + 1) * (e + 2) / 2) % mod;
    }
}

inline void solve(int) {
    cin >> n >> q;
    A = B = 1;
    for (int i = 1; i <= n; i++) { cin >> a[i], g = gcd(g, a[i]); }
    for (int i = 1; i <= q; i++) { cin >> b[i], B = max(B, b[i]); }
    for (int i = 1; i <= n; i++) {
        a[i] /= g, A = max(A, a[i]), c[a[i]]++;
    }
    init(B);
    for (int d = 1; d <= A; d++) {
        for (int j = d; j <= A; j += d) { s[d] += c[j]; }
    }
    for (int d = 1; d <= B; d++) {
        if (s[d] < n - 3) { continue; }
        t = n - s[d], h = 1, x = d;
        for (; x > 1;) {
            y = p[x], e = 0, k = 1;
            for (; x % y == 0;) { x /= y, k *= y, e += n - s[k]; }
            for (int j = 0; j < e; j++) {
                if (h > B / y) {
                    h = B + 1;
                    break;
                }
                h *= y;
            }
            if (h > B) { break; }
        }
        if (h > B) { continue; }
        k = 3 - t, w = k >= 2 ? (k == 3 ? 1 : 3) : 6;
        for (int i = 0; i < k; i++) { w = 1LL * w * (n - t - i) % mod; }
        for (int j = h; j <= B; j += h) { ans[j] = d, cnt[j] = 1LL * w * f[j / h] % mod; }
    }
    for (int i = 1; i <= q; i++) { cout << 1LL * g * ans[b[i]] << " " << cnt[b[i]] << "\n"; }
}
} // namespace TANGYIXIAO

signed main() {
    freopen("isogeny.in", "r", stdin);
    freopen("isogeny.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    TANGYIXIAO::solve(1);
    return 0;
}
