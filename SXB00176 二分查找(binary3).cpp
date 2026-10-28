#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, x, a[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    int l = 1, r = n, ans = -1;
    for (; l <= r;) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            ans = mid;
            break;
        } else if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
