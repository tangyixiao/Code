#include <bits/stdc++.h>
using namespace std;

signed main() {
    int x;
    cin >> x;
    if (x > 0) {
        cout << x + 1 << "\n";
    } else if (x == 0) {
        cout << 0 << "\n";
    } else {
        cout << x - 1 << "\n";
    }
    return 0;
}
