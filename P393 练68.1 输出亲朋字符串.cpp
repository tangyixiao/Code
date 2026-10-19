#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
char s[N], t[N];

inline void input() {
    cin >> s;
}

inline void solve() {
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        t[i] = s[i] + s[(i + 1) % l];
    }
    cout << t << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}