#include <bits/stdc++.h>
using namespace std;
int n, ans;
inline int query(int x, int k, int t) {
    for (int i = 2; i <= x; i++) {
        t = (t + k) % i;
    }
    return t + 1;
}
signed main() {
    cin >> n;
    for (;;) {
        int k = query(n, 2, 0);
        if (k == n) {
            ans += n * 2;
            break;
        }
        ans += (n - k);
        n -= (n - k);
    }
    cout << ans;
    return 0;
}