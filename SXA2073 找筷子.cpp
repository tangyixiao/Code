#include <bits/stdc++.h>
using namespace std;

int n, x, ans;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ans ^= x;
    }
    cout << ans << "\n";
    return 0;
}
