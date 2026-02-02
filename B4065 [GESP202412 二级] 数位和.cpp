#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, x, num, ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        num = 0;
        while (x) {
            num += x % 10;
            x /= 10;
        }
        ans = max(ans, num);
    }
    cout << ans;
    return 0;
}