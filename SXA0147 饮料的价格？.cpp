#include <bits/stdc++.h>
using namespace std;

int n;
double p;

signed main() {
    cin >> n;
    if (n == 1) {
        p = 5;
    } else if (n <= 5) {
        p = 4.5;
    } else if (n <= 10) {
        p = 4;
    } else {
        p = 3.5;
    }
    cout << fixed << setprecision(1) << n * p << "\n";
    return 0;
}
