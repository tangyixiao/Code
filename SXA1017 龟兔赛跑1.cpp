#include <bits/stdc++.h>
using namespace std;

int x, y, s;

signed main() {
    cin >> x >> y;
    s = 20 * x;
    cout << 20 + (s + y - x - 1) / (y - x) << "\n";
    return 0;
}