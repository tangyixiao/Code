#include <bits/stdc++.h>
using namespace std;

const int N = 15 + 5;

char s[N][N];
int n, m, a[N];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
}

inline void dfs(int p, int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << (i ? " " : "") << s[a[i]];
        }
        cout << "\n";
        return;
    }
    for (int i = p; i <= n - m + k; i++) {
        a[k] = i, dfs(i + 1, k + 1);
    }
}

inline void solve() {
    dfs(0, 0);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}