#include <bits/stdc++.h>
using namespace std;

const int N = 32 + 5;

char s[N];

inline void input() {
    cin >> s;
}

inline void solve() {
    int n = strlen(s);
    if (n >= 3 && s[n - 3] == 'i' && s[n - 2] == 'n' && s[n - 1] == 'g') {
        n -= 3;
    } else if (n >= 2 && s[n - 2] == 'e' && s[n - 1] == 'r') {
        n -= 2;
    } else if (n >= 2 && s[n - 2] == 'l' && s[n - 1] == 'y') {
        n -= 2;
    }
    s[n] = '\0';
    cout << s << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}