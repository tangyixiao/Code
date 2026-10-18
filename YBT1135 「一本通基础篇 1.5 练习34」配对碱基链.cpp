#include <bits/stdc++.h>
using namespace std;

char s[1005];

inline void input() {
    cin >> s;
    return;
}

inline char cv(char c) {
    if (c == 'A') {
        return 'T';
    }
    if (c == 'T') {
        return 'A';
    }
    if (c == 'G') {
        return 'C';
    }
    return 'G';
}

inline void solve() {
    for (int i = 0; s[i]; i++) {
        cout << cv(s[i]);
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}