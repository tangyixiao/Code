#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, w, i;
    cin >> n >> w;
    for (i = 0; i <= n; i++) {
        if (3 * i + 4 * (n - i) == w) {
            cout << i << " " << n - i << "\n";
        }
    }
    return 0;
}
