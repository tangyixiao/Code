#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, x[N], y[N];
long long ans;

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(y, y + n);
    for (int i = 0; i < n; i++) {
        ans += abs(y[i] - y[n / 2]);
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++) {
        x[i] -= i;
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++) {
        ans += abs(x[i] - x[n / 2]);
    }
    cout << ans << "\n";
    return 0;
}
