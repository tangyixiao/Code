#include <bits/stdc++.h>
using namespace std;

const int N = 70, SZ = 6005, BASE = 3000;
int n, tot;
int a[N][N];
bitset<SZ> f[N][N];

void put(int i, int j, bitset<SZ> s, int v) {
    if (v >= 0) {
        f[i][j] |= (s << v);
        f[i][j] |= (s >> v);
    } else {
        f[i][j] |= (s >> (-v));
        f[i][j] |= (s << (-v));
    }
}

signed main() {
    cin >> n;
    tot = 2 * n - 1;
    for (int i = 1; i <= tot; i++) {
        int m = min(i, 2 * n - i);
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int v = a[tot][1];
    f[tot][1][BASE + v] = 1;
    f[tot][1][BASE - v] = 1;
    for (int i = tot; i >= 2; i--) {
        int m = min(i, 2 * n - i);
        for (int j = 1; j <= m; j++) {
            if (f[i][j].none()) {
                continue;
            }
            int lim = min(i - 1, 2 * n - (i - 1));
            int t1, t2;
            if (i <= n) {
                t1 = j;
                t2 = j - 1;
            } else {
                t1 = j;
                t2 = j + 1;
            }
            if (t1 >= 1 && t1 <= lim) {
                bitset<SZ> s = f[i][j];
                put(i - 1, t1, s, a[i - 1][t1]);
            }
            if (t2 >= 1 && t2 <= lim) {
                bitset<SZ> s = f[i][j];
                put(i - 1, t2, s, a[i - 1][t2]);
            }
        }
    }
    int ans = 0;
    for (; ans <= BASE; ans++) {
        if (f[1][1][BASE + ans]) {
            break;
        }
        if (f[1][1][BASE - ans]) {
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
