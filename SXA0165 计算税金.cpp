#include <bits/stdc++.h>
using namespace std;

double x, t;

signed main() {
    cin >> x;
    if (x >= 10000) {
        t = x * 0.05;
    } else {
        if (x >= 5000) {
            t = x * 0.03;
        } else {
            if (x >= 1000) {
                t = x * 0.02;
            } else {
                t = 0;
            }
        }
    }
    cout << fixed << setprecision(2) << "Tax=" << t << "yuan" << "\n";
    return 0;
}
