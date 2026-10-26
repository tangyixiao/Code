#include <bits/stdc++.h>
using namespace std;
int n, i, mx, d;
signed main() {
    cin >> n;
    mx = 0;
    for (i = 0; i < 4; i++) {
        d = n % 10, n /= 10;
        if (d > mx) {
            mx = d;
        }
    }
    cout << mx << "\n";
    return 0;
}
