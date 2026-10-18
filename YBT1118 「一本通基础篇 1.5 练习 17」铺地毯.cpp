#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N][4], x, y;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }
    cin >> x >> y;
}

inline void solve() {
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i][0] <= x && x <= a[i][0] + a[i][2] && a[i][1] <= y &&
            y <= a[i][1] + a[i][3]) {
            ans = i;
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
