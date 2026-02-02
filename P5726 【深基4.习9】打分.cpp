#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int sum, maxn, minn = inf, n;
double avg;
signed main() {
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        maxn = max(maxn, a);
        minn = min(minn, a);
        sum += a;
    }
    avg = 1.0 * (sum - maxn - minn) / (n - 2);
    cout << fixed << setprecision(2) << avg;
    return 0;
}