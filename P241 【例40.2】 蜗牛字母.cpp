#include <bits/stdc++.h>
using namespace std;

char ch;

inline void input() {
    cin >> ch;
}

inline void solve() {
    if (ch >= 'A' && ch <= 'Z') {
        cout << (int)ch << "\n";
    } else {
        cout << (char)(ch - 'a' + 'A') << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}