#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int m, n;
int a[N], q[N], hh, tt, ans;

inline void input() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        bool f = false;
        for (int j = hh; j < tt; ++j) {
            if (q[j] == a[i]) {
                f = true;
            }
        }
        if (!f) {
            ++ans;
            if (tt - hh == m) {
                ++hh;
            }
            q[tt++] = a[i];
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
