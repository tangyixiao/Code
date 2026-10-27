#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N], b[N];
int n, m, i = 1, j = 1, ans = 0;
signed main() {
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= m; i++) {
        cin >> b[i];
    }
    i = 1, j = 1;
    while (i <= n || j <= m) {
        long long s = a[i], t = b[j];
        while (s != t) {
            if (s < t) {
                i++, s += a[i], ans++;
            } else {
                j++, t += b[j], ans++;
            }
        }
        i++, j++;
    }
    cout << ans << "\n";
    return 0;
}
