#include <bits/stdc++.h>
using namespace std;

int n;
double x, mx;

signed main() {
    cin >> n;
    mx = -1e18;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x > mx) {
            mx = x;
        }
    }
    cout << fixed << setprecision(2) << mx << "\n";
    return 0;
}
