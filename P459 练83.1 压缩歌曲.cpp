#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long m, a[N], b[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    long long s = 0, t = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i], t += b[i];
    }
    if (s <= m) {
        cout << 0 << "\n";
        return 0;
    }
    if (t > m) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - b[i];
    }
    sort(b + 1, b + n + 1, greater<long long>());
    int ans = 0;
    for (; ans < n && s > m; ans++) {
        s -= b[ans + 1];
    }
    cout << ans << "\n";
    return 0;
}
