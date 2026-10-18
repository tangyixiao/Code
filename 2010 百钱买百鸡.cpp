#include <bits/stdc++.h>
using namespace std;

int n, m;

inline void input() {
    cin >> n >> m;
}

inline void solve() {
    for (int a = 1; a <= m - 2; a++) {
        for (int b = 1; a + b < m; b++) {
            int c = m - a - b;
            if (15 * a + 10 * b + 5 * c == n) {
                printf("mu:%d gong:%d xiao:%d\n", a, b, c);
            }
        }
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