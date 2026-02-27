#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 21;
int n, m, k, dp[N][N][N];
inline int f(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a >= N || b >= N || c >= N) {
        return f(N - 1, N - 1, N - 1);
    }
    if (dp[a][b][c]) {
        return dp[a][b][c];
    }
    if (a < b && b < c) {
        return dp[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
    }
    return dp[a][b][c] = f(a - 1, b, c) + f(a - 1, b, c - 1) + f(a - 1, b - 1, c) - f(a - 1, b - 1, c - 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int l = 0; l <= N; l++) {
                f(i, j, l);
            }
        }
    }
    while (cin >> n >> m >> k) {
        if (n == -1 && m == -1 && k == -1) {
            break;
        }
        cout << "w(" << n << ", " << m << ", " << k << ") = " << f(n, m, k) << "\n";
    }
    return 0;
}