#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, q, i, k, l, r, mid, p;
long long a[N], mx[N], sm[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    mx[0] = 0, sm[0] = 0;
    for (i = 1; i <= n; i++) {
        mx[i] = max(mx[i - 1], a[i]);
        sm[i] = sm[i - 1] + a[i];
    }
    for (i = 1; i <= q; i++) {
        cin >> k;
        l = 0, r = n;
        for (; l < r;) {
            mid = (l + r + 1) >> 1;
            if (mx[mid] <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (i > 1) {
            cout << " ";
        }
        cout << sm[l];
    }
    cout << "\n";
    return 0;
}
