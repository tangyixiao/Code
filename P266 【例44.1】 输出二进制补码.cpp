#include <bits/stdc++.h>
using namespace std;

unsigned int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 31; i >= 0; i--) {
        cout << ((n >> i) & 1u);
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
