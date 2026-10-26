#include <bits/stdc++.h>
using namespace std;

int n, m, v, best, i;

signed main() {
    cin >> n;
    best = 0;
    for (i = 1; i * 2 < n; i++) {
        v = (n - 2 * i) * (n - 2 * i) * i;
        if (v > best) {
            best = v;
        }
    }
    cout << best << "\n";
    return 0;
}
