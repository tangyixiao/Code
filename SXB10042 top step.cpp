#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q, a[N], b[N], mx[N], h, t;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    long long s = 0;
    mx[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        mx[i] = max(mx[i - 1], a[i]);
        b[i] = a[i];
    }
    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        long long cur = 0, ans = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] > k) {
                break;
            }
            cur += b[j];
            ans = cur;
        }
        cout << ans;
        if (i < q) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
