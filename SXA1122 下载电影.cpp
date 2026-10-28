#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, m, a[N], s, res;
double ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        if (i > m) {
            s -= a[i - m];
        }
        if (i >= m) {
            res = max(res, s);
        }
    }
    ans = (double)res / m;
    cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}
