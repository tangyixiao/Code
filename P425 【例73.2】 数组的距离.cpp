#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N], b[N], n, m;

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    return;
}

inline void solve() {
    sort(a, a + n), sort(b, b + m);
    int i = 0, j = 0, ans = 2e8 + 5;
    while (i < n && j < m) {
        ans = min(ans, abs(a[i] - b[j]));
        if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
