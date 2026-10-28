#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, i;
long long m, a[N], l, r, mid, s, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    l = 0, r = 0;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }
    ans = 0;
    for (; l <= r;) {
        mid = (l + r) >> 1;
        s = 0;
        for (i = 1; i <= n; i++) {
            if (a[i] > mid) {
                s += a[i] - mid;
            }
        }
        if (s >= m) {
            ans = mid, l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
