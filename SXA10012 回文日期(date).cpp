#include <bits/stdc++.h>
using namespace std;

int s, e, i, y, m, d, cnt, v;
int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool ok(int yy, int mm, int dd) {
    if (mm < 1 || mm > 12) {
        return false;
    }
    int lim = md[mm];
    if (mm == 2 && ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)) {
        lim = 29;
    }
    if (dd < 1 || dd > lim) {
        return false;
    }
    return true;
}

signed main() {
    cin >> s >> e;
    cnt = 0;
    for (y = 1000; y <= 9999; y++) {
        int t = y, r = 0;
        for (i = 0; i < 4; i++) {
            r = r * 10 + t % 10;
            t /= 10;
        }
        m = r / 100;
        d = r % 100;
        if (!ok(y, m, d)) {
            continue;
        }
        v = y * 10000 + m * 100 + d;
        if (v >= s && v <= e) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
