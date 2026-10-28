#include <bits/stdc++.h>
using namespace std;
signed main() {
    long long n, a, b, p, ans = 0;
    cin >> n >> a >> b;
    for (p = 1; p < n; p++) {
        long long v = a / p, w = b / (n - p);
        long long s = v < w ? v : w;
        if (s > ans) {
            ans = s;
        }
    }
    cout << ans << "\n";
    return 0;
}
