#include <bits/stdc++.h>
using namespace std;

const int N = 25 + 5;
char s[N];

inline bool chk(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return c == '_' || (c >= '0' && c <= '9');
}

inline void input() {
    cin >> s;
    return;
}

inline void solve() {
    if (s[0] >= '0' && s[0] <= '9') {
        cout << "no\n";
        return;
    }
    for (int i = 0; s[i]; i++) {
        if (!chk(s[i])) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}