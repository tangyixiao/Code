#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N];
long long m;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    long long mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, (long long)a[i]);
    }
    long long l = 0, r = mx, ans = 0;
    for (; l <= r;) {
        long long mid = (l + r) / 2, s = 0;
        for (int i = 1; i <= n; i++) {
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
