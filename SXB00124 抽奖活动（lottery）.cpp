#include <bits/stdc++.h>
using namespace std;

int w[5], t[5], n, c, ans;

signed main() {
    cin >> w[1] >> w[2] >> w[3] >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[1] >> t[2] >> t[3];
        c = 0;
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (t[j] == w[k]) {
                    c++;
                }
            }
        }
        if (c == 3) {
            ans += 500;
        } else if (c == 2) {
            ans += 200;
        } else if (c == 1) {
            ans += 100;
        }
    }
    cout << ans << "\n";
    return 0;
}
