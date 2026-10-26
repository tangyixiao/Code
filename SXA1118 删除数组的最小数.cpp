#include <bits/stdc++.h>
using namespace std;

int n, mn, f;
int a[105];

signed main() {
    cin >> n;
    mn = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < mn) {
            mn = a[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == mn) {
            continue;
        }
        if (f) {
            cout << " ";
        }
        cout << a[i];
        f = 1;
    }
    cout << "\n";
    return 0;
}
