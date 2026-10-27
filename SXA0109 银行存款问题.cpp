#include <bits/stdc++.h>
using namespace std;
long long n, m;
double rate, ans;
signed main() {
    scanf("%lld%lld", &n, &m);
    if (m == 1) {
        rate = 0.0325;
    } else if (m == 2) {
        rate = 0.0375;
    } else if (m <= 4) {
        rate = 0.0425;
    } else {
        rate = 0.0475;
    }
    ans = n * (1 + rate * m);
    printf("%.1f\n", ans);
    return 0;
}
