#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N], g[N], k[N], n, m, t, ans = -1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= n; i++) {
        if ((x >= a[i] && x <= a[i] + g[i]) && (y >= b[i] && y <= b[i] + k[i]))
            ans = i;
    }
    cout << ans;
    return 0;
}
