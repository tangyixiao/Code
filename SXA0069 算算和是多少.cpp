#include <bits/stdc++.h>
using namespace std;

int x;

signed main() {
    cin >> x;
    cout << x + x % 10 * 100 + x / 10 % 10 * 10 + x / 100 << "\n";
    return 0;
}
