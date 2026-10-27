#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long lo = 1, hi = (a + b) / n + 1;
    long long ans = 1;
    for (; lo <= hi;) {
        long long mid = (lo + hi) / 2;
        if (a / mid + b / mid >= n) {
            ans = mid, lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
