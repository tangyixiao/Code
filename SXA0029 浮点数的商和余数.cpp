#include <bits/stdc++.h>
using namespace std;

double a, b;
long long k;

signed main() {
    cin >> a >> b;
    k = (long long)(a / b);
    cout << k << " " << fixed << setprecision(4) << a - k * b << "\n";
    return 0;
}
