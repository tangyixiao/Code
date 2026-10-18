#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, p[N];

inline void input() {
    p[0] = 0;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i - 1] + m) % i;
        }
        cout << p[n] + 1 << "\n";
    }
}

inline void solve() {
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
