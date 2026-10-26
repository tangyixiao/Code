#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, ans, bl, br, l[N], r[N];
long long a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        l[i] = i;
        while (l[i] > 1 && a[l[i] - 1] >= a[i]) {
            l[i] = l[l[i] - 1];
        }
    }
    for (int i = n; i >= 1; i--) {
        r[i] = i;
        while (r[i] < n && a[r[i] + 1] >= a[i]) {
            r[i] = r[r[i] + 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        long long s = a[i] * (r[i] - l[i] + 1);
        if (s > ans) {
            ans = s;
            bl = l[i];
            br = r[i];
        }
    }
    cout << bl << " " << br << " " << ans << "\n";
    return 0;
}
