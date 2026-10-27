#include <bits/stdc++.h>
using namespace std;
int m, n, i;
signed main() {
    cin >> m >> n;
    if (m < n) {
        int t = m;
        m = n, n = t;
    }
    for (i = m; i >= n; i--) {
        if (i < m) {
            cout << " ";
        }
        cout << i;
    }
    cout << "\n";
    return 0;
}
