#include <bits/stdc++.h>
using namespace std;
int m, n, x;
signed main() {
    cin >> m >> n >> x;
    for (; x >= (m + n - 1) / n;) {
        x -= (m + n - 1) / n;
        n += m / n;
    }
    cout << n << "\n";
    return 0;
}
