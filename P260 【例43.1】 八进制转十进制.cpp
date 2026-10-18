#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5;

string s;

inline void input() {
    cin >> s;
}

inline void solve() {
    int n = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        n = n * 8 + s[i] - '0';
    }
    cout << n << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
