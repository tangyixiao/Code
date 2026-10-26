#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
int w, n, a[N], ans, l, r;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    l = 1;
    r = n;
    for (; l <= r;) {
        if (l == r) {
            ans++;
            break;
        }
        if (a[l] + a[r] <= w) {
            l++;
            r--;
        } else {
            r--;
        }
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
