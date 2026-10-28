#include <bits/stdc++.h>
using namespace std;

double b[10];

double h(double x, double y, double z) {
    double p = (x + y + z) / 2;
    return sqrt(p * (p - x) * (p - y) * (p - z));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 9; i++) {
        cin >> b[i];
    }
    double s = h(b[1], b[2], b[7]) + h(b[7], b[3], b[8]) + h(b[8], b[4], b[9]) + h(b[9], b[5], b[6]);
    cout << fixed << setprecision(3) << s << "\n";
    return 0;
}
