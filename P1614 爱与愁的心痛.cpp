#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5, inf = 1e9;
int n, m, a[N], suma[N], ans = inf;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        suma[i] = suma[i - 1] + a[i];
    }
    for (int i = m; i <= n; i++) {
        ans = min(ans, suma[i] - suma[i - m]);
    }
    cout << ans;
    return 0;
}