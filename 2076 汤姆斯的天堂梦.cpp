#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const long long I = 1e15;

int n, k[N], x, c;
long long f[N][N];

inline void input() {
    cin >> n;
    f[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            f[i][j] = I;
            while (cin >> x && x) {
                cin >> c;
                f[i][j] = min(f[i][j], f[i - 1][x] + c);
            }
        }
    }
}

inline void solve() {
    long long r = I;
    for (int j = 1; j <= k[n]; j++) {
        r = min(r, f[n][j]);
    }
    cout << r << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}