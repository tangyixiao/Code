#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
string s;

inline void input() { cin >> s; }

inline void solve() {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            continue;
        }
        bool l = i * 2 + 1 < n && s[i * 2 + 1] != '#';
        bool r = i * 2 + 2 < n && s[i * 2 + 2] != '#';
        if (l != r) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}