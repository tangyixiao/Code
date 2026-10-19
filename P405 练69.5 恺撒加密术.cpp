#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

char s[N];

inline void input() {
    cin.getline(s, sizeof(s));
}

inline void solve() {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] == 'z' ? 'a' : s[i] + 1);
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] == 'Z' ? 'A' : s[i] + 1);
        }
    }
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