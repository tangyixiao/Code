#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    int a = n, b = n + 8, c = n + 6;
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << fixed << setprecision(1) << (a + b + c) / 3.0 << "\n";
    return 0;
}
