#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n;
char s[N];

inline void input() {
    cin >> n;
}

inline void dfs(int d, int o, int c) {
    if (d == 2 * n) {
        for (int i = 0; i < d; i++) {
            cout << s[i];
        }
        cout << "\n";
        return;
    }
    if (o < n) {
        s[d] = '(', dfs(d + 1, o + 1, c);
    }
    if (c < o) {
        s[d] = ')', dfs(d + 1, o, c + 1);
    }
}

inline void solve() {
    dfs(0, 0, 0);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
