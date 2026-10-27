#include <bits/stdc++.h>
using namespace std;

int n, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; 8 * x + 2 * y < 10 * n; y++) {
            int z = 10 * n - 8 * x - 2 * y;
            if (x + y + z > 30) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
