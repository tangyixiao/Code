#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
bool flag;
int t, a[N], n, sum[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++) {
            if (sum[i] == sum[n] - sum[i]) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
        flag = false;
    }
    return 0;
}