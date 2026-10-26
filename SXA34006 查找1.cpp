#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        int p = lower_bound(a + 1, a + n + 1, x) - a;
        if (p <= n && a[p] == x) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
