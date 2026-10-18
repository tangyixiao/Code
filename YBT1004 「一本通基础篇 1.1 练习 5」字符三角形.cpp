#include <bits/stdc++.h>
using namespace std;

char c;

inline void input() {
    cin >> c;
}

inline void solve() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << c;
        }
        cout << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
