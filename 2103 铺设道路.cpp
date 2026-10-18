#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, d[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
}

inline void solve() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] > d[i - 1]) {
            ans += d[i] - d[i - 1];
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
