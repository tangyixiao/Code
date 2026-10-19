#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
char s[N];
int c[N];

inline void input() {
    cin >> s;
    return;
}

inline void solve() {
    for (int i = 0; s[i]; i++) {
        c[s[i] - 'a']++;
    }
    for (int i = 0; s[i]; i++) {
        if (c[s[i] - 'a'] == 1) {
            cout << s[i] << "\n";
            return;
        }
    }
    cout << "no\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}