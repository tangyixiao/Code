#include <bits/stdc++.h>
using namespace std;

signed main() {
    int x, y, z;
    cin >> x >> y >> z;
    if (x + y + z >= 270) {
        cout << "beijing" << "\n";
    } else {
        cout << "nanjing" << "\n";
    }
    return 0;
}
