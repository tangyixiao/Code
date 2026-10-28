#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, x, t, i, bi;
long long d[N], mn, cur;
string op;

signed main() {
    cin >> n;
    d[1] = 0;
    for (i = 2; i <= n; i++) {
        cin >> op;
        if (op == "Patrik") {
            cin >> t;
            d[i] = t;
        } else {
            cin >> x >> t;
            d[i] = d[x] + t;
        }
    }
    if (n < 2) {
        cout << "0 1 1" << "\n";
        return 0;
    }
    mn = -1, bi = 2;
    for (i = 2; i <= n; i++) {
        cur = d[i] - d[i - 1];
        if (mn < 0 || cur < mn) {
            mn = cur, bi = i;
        }
    }
    cout << mn << " " << bi - 1 << " " << bi << "\n";
    return 0;
}
