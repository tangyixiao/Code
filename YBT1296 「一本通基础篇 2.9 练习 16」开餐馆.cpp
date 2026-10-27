#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int T, n, k, m[N], p[N];
long long f[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (; T--;) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> m[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = p[i];
            for (int j = 1; j < i; ++j) {
                if (m[i] - m[j] > k && f[j] + p[i] > f[i]) {
                    f[i] = f[j] + p[i];
                }
            }
            if (f[i] > ans) {
                ans = f[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
