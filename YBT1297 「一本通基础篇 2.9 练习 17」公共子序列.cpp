#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;
int n, f[N][N];

inline void input() {
    return;
}

inline void solve() {
    string a, b;
    while (cin >> a >> b) {
        int la = a.size(), lb = b.size();
        for (int i = 0; i <= la; i++) {
            f[i][0] = 0;
        }
        for (int j = 0; j <= lb; j++) {
            f[0][j] = 0;
        }
        for (int i = 1; i <= la; i++) {
            for (int j = 1; j <= lb; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (a[i - 1] == b[j - 1]) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
                }
            }
        }
        cout << f[la][lb] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}