#include <bits/stdc++.h>
using namespace std;

int n, k, i, j, ans;
int a[1005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ans = 0;
    j = 1;
    for (i = 1; i <= n; i++) {
        for (; a[i] - a[j] > k;) {
            j++;
        }
        if (i - j + 1 > ans) {
            ans = i - j + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
