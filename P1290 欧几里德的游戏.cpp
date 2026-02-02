#include <bits/stdc++.h>
using namespace std;
int T;
inline bool BaBaBoYi(int x, int y, bool p) {
    if (x == y) {
        return p;
    }
    if (y / x >= 2) {
        return p;
    }
    return BaBaBoYi(y - x, x, !p);
}
signed main() {
    cin >> T;
    for (int x, y; T--;) {
        cin >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        if (BaBaBoYi(x, y, true)) {
            cout << "Stan wins\n";
        } else {
            cout << "Ollie wins\n";
        }
    }
    return 0;
}