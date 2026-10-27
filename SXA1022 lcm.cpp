#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long m, n, a, b, g, t;
    cin >> m >> n;
    a = m, b = n;
    for (; b;) {
        t = a % b;
        a = b;
        b = t;
    }
    g = a;
    cout << m / g * n << "\n";
    return 0;
}
