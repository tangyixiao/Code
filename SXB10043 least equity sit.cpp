#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, mx = 0;
    cin >> n >> m;
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    int ma = mx + m;
    int lo = 0, hi = m + mx;
    for (; lo < hi;) {
        int mid = (lo + hi) / 2;
        long long c = 0;
        for (int i = 1; i <= n; i++) {
            if (mid > a[i]) {
                c += mid - a[i];
            }
        }
        if (c >= m) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << " " << ma << "\n";
    return 0;
}
