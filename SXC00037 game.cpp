#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, t, a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (; t--;) {
        cin >> n;
        int s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s ^= a[i];
        }
        if (s != 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
