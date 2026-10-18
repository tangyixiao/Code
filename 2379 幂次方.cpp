#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;

inline void input() {
    cin >> n;
}

inline void f(int x) {
    bool t = 1;
    for (int i = 20; i >= 0; i--) {
        if (x >> i & 1) {
            if (!t) {
                cout << "+";
            }
            t = 0;
            cout << "2";
            if (!i) {
                cout << "(0)";
            } else if (i > 1) {
                cout << "(";
                f(i);
                cout << ")";
            }
        }
    }
    return;
}

inline void solve() {
    input();
    f(n);
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}