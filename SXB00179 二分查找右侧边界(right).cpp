#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, i, x, lo, hi, mid;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> x;
        lo = 1;
        hi = n;
        int ans = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (a[mid] <= x) {
                if (a[mid] == x) {
                    ans = mid;
                }
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (i > 1) {
            cout << " ";
        }
        cout << ans;
    }
    cout << "\n";
    return 0;
}
