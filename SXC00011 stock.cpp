#include <bits/stdc++.h>
using namespace std;

const int N = 255;
int n, t, x, y, ans;
bitset<N> r[N], tmp;

signed main() {
    cin >> n >> t;
    for (int i = 1; i <= t; i++) {
        cin >> x >> y;
        if (x == y) {
            ans++;
            continue;
        }
        if (r[y].test(x)) {
            ans++;
            continue;
        }
        tmp = r[y];
        tmp.set(y);
        for (int a = 1; a <= n; a++) {
            if (a == x || r[a].test(x)) {
                r[a] |= tmp;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
