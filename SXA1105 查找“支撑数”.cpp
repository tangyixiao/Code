#include <bits/stdc++.h>
using namespace std;

int m, a[105];

signed main() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 2; i < m; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            cout << a[i] << "\n";
        }
    }
    return 0;
}
