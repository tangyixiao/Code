#include <bits/stdc++.h>
using namespace std;
long long n, x, s, m, t;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (cin >> x) {
        s += x;
        t = t + x > 0 ? t + x : 0;
        if (t > m) {
            m = t;
        }
    }
    cout << 2 * m - s << "\n";
    return 0;
}
