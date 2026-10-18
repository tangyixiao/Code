#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];
long long s, m, t;

signed main() {
    cin >> n;
    s = 0, m = 0, t = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        t = max(t + a[i], 0ll);
        m = max(m, t);
    }
    cout << 2 * m - s << "\n";
    return 0;
}