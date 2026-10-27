#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int a[N], b[N], n, i, j, t;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    t = 0;
    for (int d = 0; d <= 9; d++) {
        for (i = 1; i <= n; i++) {
            if (a[i] % 10 == d) {
                b[++t] = a[i];
            }
        }
    }
    for (i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << b[i];
    }
    cout << "\n";
    t = 0;
    for (int d = 0; d <= 9; d++) {
        for (i = 1; i <= n; i++) {
            if (b[i] / 10 == d) {
                a[++t] = b[i];
            }
        }
    }
    for (i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
