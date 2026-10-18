#include <bits/stdc++.h>
using namespace std;

const int N = 105;
char s[N];

inline void input() {
    cin >> s;
    return;
}

inline void solve() {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        char c = s[n - 1 - i];
        if (c >= 'a' && c <= 'z') {
            c += 'A' - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + 3) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + 3) % 26 + 'A';
        }
        cout << c;
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}