#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N], ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        ans += min(a[i], b[i]);
    }
    cout << ans;
    return 0;
}