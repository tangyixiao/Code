#include <bits/stdc++.h>
using namespace std;

int t;
string x, y;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("sub.in", "r", stdin);
    freopen("sub.out", "w", stdout);
    cin >> t;
    for (; t--;) {
        cin >> x >> y;
        int lx = x.size(), ly = y.size(), p = 0, cnt = 0;
        for (int i = 0; i < ly; i++) {
            if (y[i] == x[p]) {
                p++;
                if (p == lx) {
                    cnt++;
                    p = 0;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
