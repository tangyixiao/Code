#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, a[N], ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int k = 1; k <= n; k++) {
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && i != k && j != k) {
                    if (a[i] + a[j] == a[k]) {
                        flag = true;
                    }
                }
            }
        }
        ans += flag;
    }
    cout << ans;
    return 0;
}
