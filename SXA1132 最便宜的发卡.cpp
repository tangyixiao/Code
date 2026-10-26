#include <bits/stdc++.h>
using namespace std;

int n, m, x, mn = 1e9 + 5;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mn = min(mn, x);
    }
    if (mn <= m) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    cout << mn << "\n";
    return 0;
}
