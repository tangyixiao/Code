#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, i;
long long a[N], pre[N], res[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (i = 1; i <= n; i++) {
        if (i > 1 && a[i] == a[i - 1]) {
            res[i] = res[i - 1];
            continue;
        }
        int m = upper_bound(a + 1, a + n + 1, a[i]) - a - 1;
        long long cur = pre[m];
        while (m < n && a[m + 1] <= cur) {
            m++;
            cur = pre[m];
        }
        res[i] = cur;
    }
    for (i = 1; i <= n; i++) {
        int j = lower_bound(a + 1, a + n + 1, a[i]) - a;
        cout << res[j];
        if (i < n) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
