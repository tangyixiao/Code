#include <bits/stdc++.h>
using namespace std;

int a, b, c;

signed main() {
    cin >> a >> b >> c;
    if (c == 0) {
        cout << "Division by zero condition\n";
    } else {
        cout << (a + b) / c << "\n";
    }
    return 0;
}
