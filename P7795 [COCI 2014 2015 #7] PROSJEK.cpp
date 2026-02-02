#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const double eps = 1e-6;
int n, k, a[N];
double b[N];
bool check(double mid) {
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i] - mid;
    }
    double res = -1, mnv = 1e9;
    for (int i = k; i <= n; i++) {
        mnv = min(mnv, b[i - k]);
        res = max(res, b[i] - mnv);
    }
    return res >= 0;
}
main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double l = 1, r = 1e6;
    while (l + eps < r) {
        double mid = (l + r) / 2.0;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.6lf\n", l);
    return 0;
}
