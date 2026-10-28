#include <bits/stdc++.h>
using namespace std;

int n, a[105];

signed main() {
    int i, j, t;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (a[i] < a[j]) {
                t = a[i], a[i] = a[j], a[j] = t;
            }
        }
    }
    int f = 0;
    for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
            if (f) {
                cout << " ";
            }
            cout << a[i], f = 1;
        }
    }
    cout << "\n";
    f = 0;
    for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 1) {
            if (f) {
                cout << " ";
            }
            cout << a[i], f = 1;
        }
    }
    cout << "\n";
    return 0;
}
