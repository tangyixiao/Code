#include <bits/stdc++.h>
using namespace std;

int n, x, mx, i;

signed main() {
    cin >> n;
    mx = -1;
    for (i = 1; i <= n; i++) {
        cin >> x;
        if (x > mx) {
            mx = x;
        }
    }
    cout << mx << "\n";
    return 0;
}
