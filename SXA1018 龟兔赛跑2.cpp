#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long x, y, v, tu = 0, tr = 0, m = 0;
    cin >> x >> y;
    v = y;
    for (; tu < tr || m == 0;) {
        m++;
        tu += x;
        tr += v;
        if (v - 2 >= x) {
            v -= 2;
        }
    }
    cout << m << "\n";
    return 0;
}
