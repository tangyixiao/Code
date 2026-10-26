#include <bits/stdc++.h>
using namespace std;
int x, y, z;
signed main() {
    cin >> x >> y >> z;
    if (x + y + z >= 270) {
        cout << "beijing\n";
    } else {
        cout << "nanjing\n";
    }
    return 0;
}
