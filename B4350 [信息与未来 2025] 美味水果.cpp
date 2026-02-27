#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long ans;
int n, a[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            if (a[i] == 1) {
                break;
            }
            a[i] = sqrt(a[i]);
        }
        ans += a[i];
    }
    cout << ans;
    return 0;
}