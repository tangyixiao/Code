#include <bits/stdc++.h>
using namespace std;

long long n, s, r;

signed main() {
    cin >> n;
    if (n < 0) {
        s = -1, n = -n;
    } else {
        s = 1;
    }
    for (; n > 0;) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    cout << s * r << "\n";
    return 0;
}
