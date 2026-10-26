#include <bits/stdc++.h>
using namespace std;

int n, ans;

signed main() {
    cin >> n;
    for (int x = 0; x <= n; x++) {
        if ((x ^ (2 * x) ^ (3 * x)) == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
