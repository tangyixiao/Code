#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char s[N];
bool f[N][N];
int n;

inline void input() {
    cin >> s;
    n = strlen(s);
}

inline void solve() {
    int ans = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (s[i] != s[j]) {
                continue;
            }
            if (j - i < 2) {
                f[i][j] = 1;
            } else {
                f[i][j] = f[i + 1][j - 1];
            }
            if (f[i][j]) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
