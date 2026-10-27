#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], pre[N], res[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("beat.in", "r", stdin);
    freopen("beat.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        int m = (int)(upper_bound(a + 1, a + n + 1, a[i]) - a) - 1;
        long long cur = pre[m];
        for (; m < n && a[m + 1] <= cur;) {
            m++;
            cur = pre[m];
        }
        res[i] = (int)cur;
    }
    for (int i = 1; i <= n; i++) {
        int p = (int)(lower_bound(a + 1, a + n + 1, a[i]) - a);
        cout << res[p] << " ";
    }
    cout << "\n";
    return 0;
}
