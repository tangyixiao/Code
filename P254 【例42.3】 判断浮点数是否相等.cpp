#include <bits/stdc++.h>
using namespace std;

double a, b;

signed main() {
    cin >> a >> b;
    cout << (fabs(a - b) < 1e-8 ? "yes" : "no") << "\n";
    return 0;
}