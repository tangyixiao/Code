#include <bits/stdc++.h>
using namespace std;
double c, k, f;
signed main() {
    cin >> k;
    c = k - 273.15;
    f = c * 1.8 + 32;
    if (f > 212) {
        cout << "Temperature is too high!";
    } else {
        printf("%.2lf %.2lf", c, f);
    }
    return 0;
}