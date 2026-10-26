#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long a, b, p;
    cin >> a >> b >> p;
    long long r = 1;
    for (; b > 0;) {
        if (b & 1) {
            r = r * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    cout << r % p << "\n";
    return 0;
}
