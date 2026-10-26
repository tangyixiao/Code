#include <bits/stdc++.h>
using namespace std;

double a[305];

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    double s = 0;
    for (int i = 2; i <= n - 1; i++) {
        s += a[i];
    }
    double ave = s / (n - 2), e = 0;
    for (int i = 2; i <= n - 1; i++) {
        e = max(e, fabs(a[i] - ave));
    }
    cout << fixed << setprecision(2) << ave << " " << e << "\n";
    return 0;
}
