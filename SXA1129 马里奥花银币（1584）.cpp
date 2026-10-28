#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N], n, i, mn = 1 << 30, mx = -1;
long long tot = 0, spent = 0;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
        if (a[i] < mn) {
            mn = a[i];
        }
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    for (i = 1; i <= n; i++) {
        if (a[i] == mn) {
            spent += a[i];
        }
    }
    spent += mx;
    cout << spent << "\n";
    cout << tot - spent << "\n";
    return 0;
}
