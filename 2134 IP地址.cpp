#include <bits/stdc++.h>
using namespace std;

string s;

inline void input() {
    cin >> s;
}

inline void solve() {
    for (int i = 0; i < 32; i += 8) {
        int v = 0;
        for (int j = 0; j < 8; ++j) {
            v = v * 2 + (s[i + j] - '0');
        }
        cout << v;
        if (i != 24) {
            cout << ".";
        }
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}