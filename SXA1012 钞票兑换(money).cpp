#include <bits/stdc++.h>
using namespace std;

int n, ans;

signed main() {
    cin >> n;
    for (int c = 0; 50 * c <= n; c++) {
        for (int b = 0; 20 * b + 50 * c <= n; b++) {
            int r = n - 50 * c - 20 * b;
            if (r % 10 == 0 && r >= 0) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
