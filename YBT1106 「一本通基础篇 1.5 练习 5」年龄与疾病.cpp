#include <bits/stdc++.h>
using namespace std;

int n, c[5];

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 19) {
            c[1]++;
        } else if (a < 36) {
            c[2]++;
        } else if (a < 61) {
            c[3]++;
        } else {
            c[4]++;
        }
    }
    for (int i = 1; i <= 4; i++) {
        cout << fixed << setprecision(2) << c[i] * 100.0 / n << "%\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}