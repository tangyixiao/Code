#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], v[N], r[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m = 0;
    for (int i = 1; i <= n;) {
        int j = i;
        for (; j < n && a[j + 1] == a[i];) {
            j++;
        }
        v[++m] = a[i];
        r[m] = j - i + 1;
        i = j + 1;
    }
    int ans = 0;
    for (int i = 1; i < m; i++) {
        int t = 2 * min(r[i], r[i + 1]);
        if (t > ans) {
            ans = t;
        }
    }
    cout << ans << "\n";
    return 0;
}
