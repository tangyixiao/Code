#include <bits/stdc++.h>
using namespace std;

int d[4];

signed main() {
    int n;
    cin >> n;
    for (; n != 6174;) {
        d[0] = n / 1000;
        d[1] = n / 100 % 10;
        d[2] = n / 10 % 10;
        d[3] = n % 10;
        sort(d, d + 4);
        int lo = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];
        int hi = d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
        n = hi - lo;
        cout << hi << "-" << lo << "=" << n << "\n";
    }
    return 0;
}
