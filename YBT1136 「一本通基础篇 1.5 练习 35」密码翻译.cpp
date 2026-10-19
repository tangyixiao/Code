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
        if (s[i] == 'z') {
            s[i] = 'a';
        } else if (s[i] == 'Z') {
            s[i] = 'A';
        } else if (s[i] >= 'a' && s[i] < 'z') {
            s[i]++;
        } else if (s[i] >= 'A' && s[i] < 'Z') {
            s[i]++;
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}