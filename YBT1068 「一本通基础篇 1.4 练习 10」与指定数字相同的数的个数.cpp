#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], c;

inline void input() { cin >> n >> m; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == m) {
            ++c;
        }
    }
    cout << c << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}