#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N], b[N], n, i, j;
long long ans = 0;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
