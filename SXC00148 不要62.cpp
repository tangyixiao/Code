#include <bits/stdc++.h>
using namespace std;

int w[15][2], d[15];

int calc(int x) {
    if (x <= 0) {
        return 0;
    }
    int le = 0, t = x;
    for (; t > 0; t /= 10) {
        d[++le] = t % 10;
    }
    for (int i = 1; i <= le / 2; i++) {
        swap(d[i], d[le + 1 - i]);
    }
    int res = 0, p6 = 0, ok = 1;
    for (int i = 1; i <= le; i++) {
        for (int g = 0; g < d[i]; g++) {
            if (g == 4 || (p6 && g == 2)) {
                continue;
            }
            res += w[le - i][g == 6];
        }
        if (d[i] == 4 || (p6 && d[i] == 2)) {
            ok = 0;
            break;
        }
        p6 = (d[i] == 6);
    }
    res += ok;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int p = 0; p < 2; p++) {
        w[0][p] = 1;
    }
    for (int l = 1; l < 12; l++) {
        for (int p = 0; p < 2; p++) {
            int s = 0;
            for (int g = 0; g < 10; g++) {
                if (g == 4 || (p && g == 2)) {
                    continue;
                }
                s += w[l - 1][g == 6];
            }
            w[l][p] = s;
        }
    }
    int n, m;
    for (; cin >> n >> m;) {
        if (n == 0 && m == 0) {
            break;
        }
        cout << calc(m) - calc(n - 1) << "\n";
    }
    return 0;
}
