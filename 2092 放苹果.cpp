#include <bits/stdc++.h>
using namespace std;

const int N = 25;
long long c[N][N];
int t;

inline void input() {
    cin >> t;
}

inline void solve() {
    for (int i = 0; i < N; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << c[m + n - 1][n - 1] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
