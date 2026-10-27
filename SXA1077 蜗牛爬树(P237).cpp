#include <bits/stdc++.h>
using namespace std;

long long n, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n <= 3) {
        ans = 1;
    } else {
        ans = 2 * ((n - 2) / 2) + 1;
    }
    cout << ans << "\n";
    return 0;
}
