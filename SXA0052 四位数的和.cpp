#include <bits/stdc++.h>
using namespace std;

int n, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (; n > 0; n /= 10) {
        ans += n % 10;
    }
    cout << ans << "\n";
    return 0;
}
