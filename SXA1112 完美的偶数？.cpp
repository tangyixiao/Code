#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        int c = 0, t = x, ok = 1;
        for (; t;) {
            c++;
            if ((t % 10) % 2) {
                ok = 0;
            }
            t /= 10;
        }
        if (ok && c % 2 == 0 && x % 2 == 0) {
            cout << x << "\n";
        }
    }
    return 0;
}
