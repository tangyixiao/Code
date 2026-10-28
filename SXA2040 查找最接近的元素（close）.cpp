#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], n, m, i;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int t = 1; t <= m; t++) {
        int q;
        cin >> q;
        int lo = 1, hi = n, p = n + 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] >= q) {
                p = mid, hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        int ans;
        if (p == 1) {
            ans = a[1];
        } else if (p == n + 1) {
            ans = a[n];
        } else {
            int d1 = a[p] - q, d2 = q - a[p - 1];
            if (d2 <= d1) {
                ans = a[p - 1];
            } else {
                ans = a[p];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
