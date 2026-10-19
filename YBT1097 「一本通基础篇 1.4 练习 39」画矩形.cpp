#include <bits/stdc++.h>
using namespace std;

int h, w, f;
char c;

inline void input() {
    cin >> h >> w >> c >> f;
    return;
}

inline void solve() {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (f || i == 1 || i == h || j == 1 || j == w) {
                cout << c;
            } else {
                cout << " ";
            }
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