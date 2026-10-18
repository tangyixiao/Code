#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
string s;

inline void input() { cin >> s; }

inline void solve() {
    for (int i = s.size() - 1; i >= 0; --i) {
        cout << s[i];
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}