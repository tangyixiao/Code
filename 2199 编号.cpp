#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int P = 1e9 + 7;
int n, m[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (m[i] > m[j]) {
                swap(m[i], m[j]);
            }
        }
    }
}

inline void solve() {
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = ans * (m[i] - i + 1) % P;
    }
    if (ans == 0 && n && m[1] < 1) {
        ans = 0;
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}