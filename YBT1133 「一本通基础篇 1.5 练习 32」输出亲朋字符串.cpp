#include <bits/stdc++.h>
using namespace std;

const int N = 105;
char s[N];

inline void input() {
    cin.getline(s, N);
    return;
}

inline void solve() {
    int n = strlen(s);
    if (n && s[n - 1] == '\r') {
        s[--n] = 0;
    }
    for (int i = 0; i < n; i++) {
        cout << char(s[i] + s[(i + 1) % n]);
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}