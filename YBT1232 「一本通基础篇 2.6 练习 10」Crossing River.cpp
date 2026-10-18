#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int t, n, a[N];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[j] < a[i]) {
                    swap(a[j], a[i]);
                }
            }
        }
        int m = n, r = 0;
        for (; m > 3; m -= 2) {
            r += min(a[1] + 2 * a[2] + a[m], 2 * a[1] + a[m - 1] + a[m]);
        }
        r += m == 3 ? a[1] + a[2] + a[3] : m == 2 ? a[2]
                                                  : a[1];
        cout << r << "\n";
    }
    return 0;
}
