#include <bits/stdc++.h>
using namespace std;

int m, n, h;

signed main() {
    cin >> m >> n >> h;
    if (h <= m) {
        cout << 1 << "\n";
    } else {
        cout << (h - m + m - n - 1) / (m - n) + 1 << "\n";
    }
    return 0;
}
