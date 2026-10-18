#include <bits/stdc++.h>
using namespace std;

char c;

inline void input() {
    cin >> c;
}

inline void solve() {
    cout << (char)(c - 'A' + 'a') << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}