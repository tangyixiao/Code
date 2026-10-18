#include <bits/stdc++.h>
using namespace std;

const int N = 128;
long long n, f[N][10];
string ans;

inline void input() {
    cin >> n;
    for (int j = 0; j < 10; j++) {
        f[1][j] = 1;
    }
    for (int i = 2; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            long long s = 0;
            for (int k = max(0, j - 1); k <= min(9, j + 1); k++) {
                s += f[i - 1][k];
            }
            f[i][j] = s;
        }
    }
}

inline void solve() {
    int len = 1;
    for (; len < N - 1; len++) {
        long long s = 0;
        for (int j = 1; j < 10; j++) {
            s += f[len][j];
        }
        if (n <= s) {
            break;
        }
        n -= s;
    }
    int j = 1;
    for (; j < 10; j++) {
        if (n > f[len][j]) {
            n -= f[len][j];
        } else {
            break;
        }
    }
    ans += char('0' + j);
    for (int r = len - 1; r > 0; r--) {
        for (int k = max(0, j - 1); k <= min(9, j + 1); k++) {
            if (n > f[r][k]) {
                n -= f[r][k];
                continue;
            }
            ans += char('0' + k), j = k;
            break;
        }
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
