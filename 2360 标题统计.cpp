#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N];

inline void input() {
    cin.getline(s, sizeof(s));
}

inline void solve() {
    input();
    int n = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ') {
            n++;
        }
    }
    cout << n << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}