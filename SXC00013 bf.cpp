#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
double n;

signed main() {
    cout << fixed << setprecision(2);
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << n * n / (2 * PI) << "\n";
    }
    return 0;
}
