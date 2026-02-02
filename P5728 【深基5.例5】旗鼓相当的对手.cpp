#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, a[N][4], sum[N], ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
        sum[i] = a[i][1] + a[i][2] + a[i][3];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (abs(a[i][1] - a[j][1]) <= 5 && abs(a[i][2] - a[j][2]) <= 5 && abs(a[i][3] - a[j][3]) <= 5 && abs(sum[i] - sum[j]) <= 10) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}