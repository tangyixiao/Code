#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1 || j == n || i == 1 || i == n || i == (n + 1) / 2) {
                if (j == 1 || j == n) {
                    cout << "|";
                } else {
                    cout << "-";
                }
            } else {
                cout << "x";
            }
        }
        cout << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}