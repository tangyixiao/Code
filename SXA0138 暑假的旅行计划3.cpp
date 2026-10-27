#include <bits/stdc++.h>
using namespace std;

signed main() {
    int x, y, z, c = 0;
    cin >> x >> y >> z;
    if (x >= 90) {
        c++;
    }
    if (y >= 90) {
        c++;
    }
    if (z >= 90) {
        c++;
    }
    double a = (x + y + z) / 3.0;
    if (a >= 90) {
        if (c == 3) {
            cout << "beijing\n";
        } else if (c == 2) {
            cout << "xiamen\n";
        } else {
            cout << "guilin\n";
        }
    } else if (a >= 85) {
        if (x >= 85 && y >= 85 && z >= 85) {
            cout << "shanghai\n";
        } else {
            cout << "nanjing\n";
        }
    } else {
        cout << "nanjing\n";
    }
    return 0;
}
