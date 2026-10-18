#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, val[N], son[N][N], ns[N], buf[N], f[N], ans;

inline void input() {
    cin >> n;
    cin.ignore();
    string s;
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        int c = 0, j = 0, m = s.size();
        while (j < m) {
            if (s[j] >= '0' && s[j] <= '9') {
                int x = 0;
                while (j < m && s[j] >= '0' && s[j] <= '9') {
                    x = x * 10 + s[j] - '0', j++;
                }
                buf[c++] = x;
            } else {
                j++;
            }
        }
        val[i] = buf[0], ns[i] = c - 1;
        for (int k = 0; k < c - 1; k++) {
            son[i][k] = buf[k + 1];
        }
    }
}

inline void solve() {
    for (int i = n; i >= 1; i--) {
        f[i] = val[i];
        for (int j = 0; j < ns[i]; j++) {
            f[i] = max(f[i], val[i] + f[son[i][j]]);
        }
        ans = max(ans, f[i]);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
