#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 2e4 + 5;
int n, g[N][M], f[N][M];

inline void input() {
    cin >> n;
    cin.ignore();
    string s;
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        int st = 0;
        while (st < (int)s.size() && s[st] == ' ') {
            st++;
        }
        for (int j = 0; st + j < (int)s.size(); j++) {
            g[i][st + j + 1] = s[st + j] == '#' ? 1 : 0;
        }
    }
}

inline void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int L = 2 * (n - i + 2) - 1, off = i - 1;
        for (int j = 0; j < L; j++) {
            int c = off + j + 1;
            if (g[i][c]) {
                f[i][j] = 0;
                continue;
            }
            if (j == 0 || j == L - 1) {
                f[i][j] = 1;
            } else {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + 1;
            }
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans * ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
