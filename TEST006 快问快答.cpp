#include <bits/stdc++.h>
using namespace std;

int y;

signed main() {
    cin >> y;
    cout << ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 1 : 0) << "\n";
    return 0;
}