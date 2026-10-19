#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int m, n, p[N], mx[N];

inline void input() { cin >> m >> n; }

inline void solve() {
    for (int i = 2; i <= n; ++i) {
        if (!p[i]) {
            for (int j = i; j <= n; j += i) {
                p[j] = i;
            }
        }
    }
    for (int i = m; i <= n; ++i) {
        cout << p[i] << (i == n ? "\n" : ",");
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}