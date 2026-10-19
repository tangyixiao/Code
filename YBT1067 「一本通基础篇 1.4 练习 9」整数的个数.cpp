#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a, c[11];

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a >= 1 && a <= 10) {
            c[a]++;
        }
    }
    cout << c[1] << "\n"
         << c[5] << "\n"
         << c[10] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
