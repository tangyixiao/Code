#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    int r = 0;
    for (int i = 2; i <= n; i++) {
        r = (r + 2) % i;
    }
    cout << r + 1 << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}