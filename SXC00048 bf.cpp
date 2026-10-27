#include <bits/stdc++.h>
using namespace std;
int n;
double pi;
signed main() {
    pi = acos(-1.0);
    while (cin >> n && n != 0) {
        cout << fixed << setprecision(2) << n * n / (2 * pi) << "\n";
    }
    return 0;
}
