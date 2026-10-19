#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, p[N][2];

inline bool ck(int a, int b, int c, int d) {
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap(c, d);
    }
    return (a < c && c < b && b < d) || (c < a && a < d && d < b);
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i][0] >> p[i][1];
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (ck(p[i][0], p[i][1], p[j][0], p[j][1])) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
