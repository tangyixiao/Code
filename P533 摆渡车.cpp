#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 105;
const int K = 1100;

int n, m, t[N], tp, cn, gc[M], qk[K];
long long sm, gg[M], gs[M], qb[K], ans;
int qh, qt;

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    sort(t + 1, t + n + 1);
}

inline bool bad(int k1, long long b1, int k2, long long b2, int k3, long long b3) {
    return (b2 - b1) * (k2 - k3) >= (b3 - b2) * (k1 - k2);
}

inline void ps(int k, long long b) {
    if (qt > qh && qk[(qt - 1) % K] == k) {
        if (qb[(qt - 1) % K] <= b) {
            return;
        }
        --qt;
    }
    while (qt - qh >= 2 && bad(qk[(qt - 2) % K], qb[(qt - 2) % K], qk[(qt - 1) % K], qb[(qt - 1) % K], k, b)) {
        --qt;
    }
    qk[qt % K] = k, qb[qt % K] = b, ++qt;
}

inline long long qd(int x) {
    while (qt - qh >= 2 && 1LL * qk[(qh + 1) % K] * x + qb[(qh + 1) % K] <= 1LL * qk[qh % K] * x + qb[qh % K]) {
        ++qh;
    }
    return 1LL * qk[qh % K] * x + qb[qh % K];
}

inline void solve() {
    qk[0] = 0, qb[0] = 0, qh = 0, qt = 1;
    for (int i = 0; i <= t[n]; ++i) {
        if (i >= m) {
            int u = (i - m) % (m + 2);
            ps(-gc[u], gg[u] + gs[u]);
        }
        while (tp < n && t[tp + 1] <= i) {
            ++tp, ++cn, sm += t[tp];
        }
        int p = i % (m + 2);
        gg[p] = 1LL * i * cn - sm + qd(i), gc[p] = cn, gs[p] = sm;
        ans = gg[p];
    }
    cout << ans << "\n";
    return;
}

signed main() {
    if (fopen("bus.in", "r")) {
        freopen("bus.in", "r", stdin);
        freopen("bus.out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}