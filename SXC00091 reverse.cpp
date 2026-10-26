#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], c[1 << 21];
long long ans;

signed main() {
    int n, i;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    c[0] = 1;
    int p = 0;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        p ^= a[i];
        ans += c[p];
        c[p]++;
    }
    cout << ans << "\n";
    return 0;
}
