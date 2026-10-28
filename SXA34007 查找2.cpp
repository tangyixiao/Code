#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q, x, a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x;
        int l = lower_bound(a + 1, a + n + 1, x) - a;
        int r = upper_bound(a + 1, a + n + 1, x) - a - 1;
        if (l > r) {
            cout << -1 << "\n";
        } else {
            for (int j = l; j <= r; j++) {
                cout << j;
                if (j < r) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
