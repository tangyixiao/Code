#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int a[N], c, n, maxn = -51, minn = 51, l, r, mid;
inline bool check() {
    int k = c;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= mid) {
            k = c;
        } else {
            k--;
        }
        if (k < 0) {
            return false;
        }
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> c >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    l = minn - 1, r = maxn + 1;
    while (l + 1 < r) {
        mid = (l + r) >> 1;
        if (check()) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
    return 0;
}
