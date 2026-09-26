#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], b[N], d, l, r, ans, x, y;
inline bool check(int x) {
    for (int i = 1, t; i <= n; i++) {
        t = y, y = max(x, y) + a[i] >= x ? 1 : -1, x = t;
    }
    return max(x, y) > 0;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("mid.in", "r", stdin), freopen("mid.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], b[i] = a[i];
    }
    sort(b + 1, b + n + 1), r = unique(b + 1, b + n + 1) - b - 1;
    for (int mid; l <= r;) {
        mid = (l + r) >> 1;
        if (check(b[mid])) {
            ans = b[mid], l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
