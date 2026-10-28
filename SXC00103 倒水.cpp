#include <bits/stdc++.h>
using namespace std;

long long n, k, low, ans;

signed main() {
    cin >> n >> k;
    ans = 0;
    while (__builtin_popcountll(n) > k) {
        low = n & (-n);
        n += low;
        ans += low;
    }
    cout << ans << "\n";
    return 0;
}
