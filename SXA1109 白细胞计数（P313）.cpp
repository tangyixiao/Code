#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 5;
double a[N];
int n, i;
signed main() {
    cin >> n;
    double mx = -1e18, mn = 1e18, s = 0;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
        }
        if (a[i] < mn) {
            mn = a[i];
        }
    }
    int fmx = 0, fmn = 0;
    for (i = 1; i <= n; i++) {
        if (fmx == 0 && a[i] == mx) {
            fmx = 1;
            continue;
        }
        if (fmn == 0 && a[i] == mn) {
            fmn = 1;
            continue;
        }
        s += a[i];
    }
    double avg = s / (n - 2), err = 0;
    fmx = 0, fmn = 0;
    for (i = 1; i <= n; i++) {
        if (fmx == 0 && a[i] == mx) {
            fmx = 1;
            continue;
        }
        if (fmn == 0 && a[i] == mn) {
            fmn = 1;
            continue;
        }
        double d = fabs(a[i] - avg);
        if (d > err) {
            err = d;
        }
    }
    cout << fixed << setprecision(2) << avg << " " << err << "\n";
    return 0;
}
