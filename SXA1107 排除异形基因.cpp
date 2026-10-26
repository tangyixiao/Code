#include <bits/stdc++.h>
using namespace std;

int n, a[205], b[205], c;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] * a[i] % 7 != 1) {
            b[++c] = a[i];
        }
    }
    for (int i = 1; i <= c; i++) {
        cout << b[i];
        if (i < c) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
