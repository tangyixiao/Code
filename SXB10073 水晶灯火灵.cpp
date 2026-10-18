#include <bits/stdc++.h>
using namespace std;

long long k, m, n;

signed main() {
    cin >> k;
    m = n = 1;
    for (; m + n <= k;) {
        long long t = m + n;
        m = n, n = t;
    }
    cout << "m=" << m << "\n"
         << "n=" << n << "\n";
    return 0;
}