#include <bits/stdc++.h>
using namespace std;

int n, x, y, ra, rb;

signed main() {
    cin >> n >> x >> y;
    for (int a = 1; a * x <= n; a++) {
        int r = n - a * x;
        if (r % y == 0 && r / y >= 1) {
            if (a > ra) {
                ra = a;
                rb = r / y;
            }
        }
    }
    cout << ra << " " << rb << "\n";
    return 0;
}
