#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long n, m, a, s = 0, mx = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s += a;
        mx = max(mx, a);
    }
    long long lo = max(mx, (s + m + n - 1) / n);
    long long hi = mx + m;
    cout << lo << " " << hi << "\n";
    return 0;
}
