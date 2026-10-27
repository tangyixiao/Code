#include <bits/stdc++.h>
using namespace std;

int n, i, ans;
long long s;

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        s = 1LL * i * i;
        if (s % 10 == i) {
            ans++;
        } else if (s % 100 == i) {
            ans++;
        } else if (s % 1000 == i) {
            ans++;
        } else if (s % 10000 == i) {
            ans++;
        } else if (s % 100000 == i) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
