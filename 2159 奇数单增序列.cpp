#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, b[N];

inline void input() {
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x & 1) {
            b[x] = 1;
        }
    }
}

inline void solve() {
    input();
    int f = 0;
    for (int i = 1; i < N; i++) {
        if (b[i]) {
            if (f) {
                cout << "," << i;
            } else {
                cout << i, f = 1;
            }
        }
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}