#include <bits/stdc++.h>
using namespace std;
long long n, lo, hi;
signed main() {
    cin >> n;
    lo = 1;
    while (lo * 2 <= n) {
        lo *= 2;
    }
    hi = lo * 2;
    if (n - lo <= hi - n) {
        cout << lo << "\n";
    } else {
        cout << hi << "\n";
    }
    return 0;
}
