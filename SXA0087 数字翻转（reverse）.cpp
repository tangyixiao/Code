#include <bits/stdc++.h>
using namespace std;

int x, r;

signed main() {
    cin >> x;
    r = x % 10 * 100 + x / 10 % 10 * 10 + x / 100;
    cout << r << "\n";
    return 0;
}
