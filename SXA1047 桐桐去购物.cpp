#include <bits/stdc++.h>
using namespace std;

long long n, m, i, j, t;

signed main() {
    cin >> n >> m;
    for (i = 0; i <= m; i++) {
        t = 3 * n - m - 14 * i;
        if (t >= 0 && t % 8 == 0) {
            j = t / 8;
            if (j >= 0 && m - i - j >= 0 && (m - i - j) % 3 == 0) {
                cout << i << " " << j << " " << m - i - j << "\n";
            }
        }
    }
    return 0;
}
