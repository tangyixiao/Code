#include <bits/stdc++.h>
using namespace std;

signed main() {
    int m, x, lo = 0x7fffffff, hi = -0x7fffffff - 1;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        lo = min(lo, x);
        hi = max(hi, x);
    }
    cout << hi - lo << "\n";
    return 0;
}
