#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, v, a[N], best;
long long s, bd, d;

signed main() {
    cin >> n;
    s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    bd = -1;
    for (int i = 1; i <= n; i++) {
        d = (long long)a[i] * n - s;
        if (d < 0) {
            d = -d;
        }
        if (bd < 0 || d < bd) {
            bd = d;
            best = a[i];
        }
    }
    cout << best << "\n";
    return 0;
}
