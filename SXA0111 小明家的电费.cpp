#include <bits/stdc++.h>
using namespace std;

double x, s;

signed main() {
    cin >> x;
    if (x <= 150) {
        s = x * 0.4463;
    } else if (x <= 400) {
        s = 150 * 0.4463 + (x - 150) * 0.4663;
    } else {
        s = 150 * 0.4463 + 250 * 0.4663 + (x - 400) * 0.5663;
    }
    cout << fixed << setprecision(1) << s << "\n";
    return 0;
}
