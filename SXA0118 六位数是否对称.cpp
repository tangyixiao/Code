#include <bits/stdc++.h>
using namespace std;
int n, a, b;
signed main() {
    cin >> n;
    a = n / 100000 * 100 + n / 10000 % 10 * 10 + n / 1000 % 10;
    b = n / 100 % 10 + n / 10 % 10 * 10 + n % 10 * 100;
    if (a == b) {
        cout << "Y" << "\n";
    } else {
        cout << "N" << "\n";
    }
    return 0;
}
