#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long d1 = 0, d2 = 1, dn;
    if (n == 1) {
        cout << d1 << endl;
    } else if (n == 2) {
        cout << d2 << endl;
    } else {
        for (int i = 3; i <= n; ++i) {
            dn = (i - 1) * (d1 + d2);
            d1 = d2;
            d2 = dn;
        }
        cout << d2 << endl;
    }

    return 0;
}