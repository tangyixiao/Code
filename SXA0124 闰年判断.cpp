#include <bits/stdc++.h>
using namespace std;

int y;

signed main() {
    cin >> y;
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    return 0;
}
