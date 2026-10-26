#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long m, n;
    cin >> m >> n;
    long long s = m * n;
    long long c = 0;
    for (long long d = 2; d * d <= s; d++) {
        if (s % d == 0) {
            c++;
        }
    }
    long long a = min(m, n), b = max(m, n);
    if (a > 1 && a * a <= s) {
        c--;
    }
    cout << c << "\n";
    return 0;
}
