#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n;
    double p = 0;
    cin >> n;
    if (n >= 30) {
        p = 1.0;
    } else if (n >= 20) {
        p = 1.2;
    } else if (n >= 10) {
        p = 1.5;
    } else {
        p = 1.8;
    }
    cout << fixed << setprecision(1) << p * n << "\n";
    return 0;
}
