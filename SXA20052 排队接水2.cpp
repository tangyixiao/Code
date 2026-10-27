#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N], n, r, i, j;
long long f[N], ans = 0;
signed main() {
    cin >> n >> r;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= r; i++) {
        f[i] = 0;
    }
    for (i = 1; i <= n; i++) {
        int k = 1;
        for (j = 2; j <= r; j++) {
            if (f[j] < f[k]) {
                k = j;
            }
        }
        f[k] += a[i], ans += f[k];
    }
    cout << ans << "\n";
    return 0;
}
