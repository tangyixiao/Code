#include <bits/stdc++.h>
using namespace std;

int n, l, r;

signed main() {
    cin >> n;
    l = 1, r = 100;
    while (true) {
        int m = (l + r) / 2;
        cout << m << "\n";
        if (m == n) {
            break;
        }
        m < n ? l = m + 1 : r = m - 1;
    }
    cout << "Win!\n";
    return 0;
}