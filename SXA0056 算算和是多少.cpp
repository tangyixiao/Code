#include <bits/stdc++.h>
using namespace std;
int x, y, z;
signed main() {
    cin >> x;
    y = (x % 10) * 100 + (x / 10 % 10) * 10 + x / 100;
    cout << x + y << "\n";
    return 0;
}
