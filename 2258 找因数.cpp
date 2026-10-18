#include <bits/stdc++.h>
using namespace std;

int a;

inline void input() {
    cin >> a;
}

inline void solve() {
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0) {
            cout << i << "\n";
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}