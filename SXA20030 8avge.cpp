#include <bits/stdc++.h>
using namespace std;
int n, i, x, s;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        s += x;
    }
    cout << fixed << setprecision(2) << (double)s / n << "\n";
    return 0;
}
