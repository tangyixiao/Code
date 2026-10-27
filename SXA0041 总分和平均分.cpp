#include <bits/stdc++.h>
using namespace std;

double x, y, z, s;

signed main() {
    cin >> x >> y >> z;
    s = x + y + z;
    if (s == (long long)s) {
        printf("%lld\n", (long long)s);
    } else {
        printf("%.1f\n", s);
    }
    printf("%.1f\n", s / 3.0);
    return 0;
}
