#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        cout << i << ":";
        if (i % 2 == 0) {
            cout << "叮叮";
        }
        if (i % 3 == 0) {
            cout << "当当";
        }
        cout << "\n";
    }
    return 0;
}
