#include <bits/stdc++.h>
using namespace std;

signed main() {
    int m, a, b;
    cin >> m >> a >> b;
    for (int x = 2; x * a <= m; x += 2) {
        int r = m - x * a;
        if (r % b == 0 && r / b > 0 && r / b % 2 == 0) {
            cout << x << " " << r / b << "\n";
        }
    }
    return 0;
}
