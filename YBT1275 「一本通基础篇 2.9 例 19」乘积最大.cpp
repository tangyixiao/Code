#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, k;
char s[N];
long long f[N][N];

inline void input() {
    cin >> n >> k;
    cin >> s;
    return;
}

inline long long val(int l, int r) {
    long long v = 0;
    for (int i = l; i <= r; i++) {
        v = v * 10 + (s[i - 1] - '0');
    }
    return v;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        f[i][1] = val(1, i);
    }
    for (int j = 2; j <= k + 1; j++) {
        for (int i = j; i <= n; i++) {
            f[i][j] = 0;
            for (int p = j - 1; p < i; p++) {
                f[i][j] = max(f[i][j], f[p][j - 1] * val(p + 1, i));
            }
        }
    }
    cout << f[n][k + 1] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
