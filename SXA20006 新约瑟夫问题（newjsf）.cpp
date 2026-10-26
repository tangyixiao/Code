#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int m, s, n, k, i, t, pos, cnt, lim, d;
bool live[N];
int out[N];
int step(int p, int dir) {
    for (;;) {
        p += dir;
        if (p > m) {
            p = 1;
        }
        if (p < 1) {
            p = m;
        }
        if (live[p]) {
            return p;
        }
    }
}
signed main() {
    cin >> m >> s >> n >> k;
    for (i = 1; i <= m; i++) {
        live[i] = true;
    }
    pos = s;
    for (t = 1; t <= m; t++) {
        lim = (t % 2 == 1) ? n : k;
        d = (t % 2 == 1) ? 1 : -1;
        if (t > 1) {
            pos = step(pos, d);
        }
        cnt = 1;
        for (; cnt < lim;) {
            pos = step(pos, d);
            cnt++;
        }
        live[pos] = false;
        out[t] = pos;
    }
    for (i = 1; i <= m; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << out[i];
    }
    cout << "\n";
    return 0;
}
