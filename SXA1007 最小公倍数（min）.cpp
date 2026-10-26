#include <bits/stdc++.h>
using namespace std;
long long m, n, a, b, t;
signed main() {
    cin >> m >> n;
    a = m, b = n;
    for (; b;) {
        t = a % b;
        a = b, b = t;
    }
    cout << m / a * n << "\n";
    return 0;
}
