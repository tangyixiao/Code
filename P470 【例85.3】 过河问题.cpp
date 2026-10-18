#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int t, n;
int a[N];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int m = n;
        long long r = 0;
        for (; m > 3; m -= 2) {
            r += min(a[2] + a[1] + a[m] + a[2], a[m] + a[m - 1] + 2 * a[1]);
        }
        r += m == 1 ? a[1] : m == 2 ? a[2]
                                    : a[1] + a[2] + a[3];
        cout << r << "\n";
    }
    return 0;
}