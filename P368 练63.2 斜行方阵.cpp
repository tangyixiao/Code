#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, a[N][N];

inline void input() { cin >> n; }

inline void solve() {
    int k = 1;
    for (int d = n - 1; d >= 1 - n; d--) {
        for (int i = 1; i <= n; i++) {
            int j = i + d;
            if (j < 1 || j > n) {
                continue;
            }
            a[i][j] = k++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}