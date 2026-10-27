#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y, z;

signed main() {
    cin >> a >> b >> c;
    x = min(a, min(b, c)), z = max(a, max(b, c)), y = a + b + c - x - z;
    if (y - x == 1 && z - y == 1) {
        cout << "TRUE" << "\n";
    } else {
        cout << "FALSE" << "\n";
    }
    return 0;
}
