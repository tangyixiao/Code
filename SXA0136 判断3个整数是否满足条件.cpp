#include <bits/stdc++.h>
using namespace std;

int a, b, c;

signed main() {
    cin >> a >> b >> c;
    if ((a + b + c) % 2 != 0) {
        cout << "Bad" << "\n";
    } else if (a + b >= c) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    return 0;
}
