#include <bits/stdc++.h>
using namespace std;

signed main() {
    int t, k;
    cin >> t >> k;
    if ((t == 1 && k == 2) || (t == 2 && k == 3) || (t == 3 && k == 1)) {
        cout << "win\n";
    } else if (t == k) {
        cout << "tie\n";
    } else {
        cout << "lose\n";
    }
    return 0;
}
