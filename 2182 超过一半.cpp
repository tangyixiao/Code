#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, c[105];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        ++c[x + 50];
    }
}

inline void solve() {
    for (int i = 0; i <= 100; ++i) {
        if (c[i] * 2 > n) {
            cout << i - 50 << "\n";
            return;
        }
    }
    cout << "no\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}