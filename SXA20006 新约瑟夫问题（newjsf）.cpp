#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int m, n, k, s, i, t, pos, cnt, dir, lim;
bool live[N];
int out[N];
signed main() {
    cin >> m >> s >> n >> k;
    for (i = 1; i <= m; i++) {
        live[i] = true;
    }
    pos = s;
    for (t = 1; t <= m; t++) {
        lim = (t % 2 == 1) ? n : k;
        dir = (t % 2 == 1) ? 1 : -1;
        cnt = 0;
        for (int guard = 0; guard < m + 1;) {
            if (live[pos]) {
                cnt++;
            }
            if (cnt == lim) {
                break;
            }
            for (;;) {
                pos += dir;
                if (pos > m) {
                    pos = 1;
                }
                if (pos < 1) {
                    pos = m;
                }
                if (live[pos]) {
                    break;
                }
            }
        }
        live[pos] = false;
        out[t] = pos;
        if (t < m) {
            for (;;) {
                pos += dir;
                if (pos > m) {
                    pos = 1;
                }
                if (pos < 1) {
                    pos = m;
                }
                if (live[pos]) {
                    break;
                }
            }
        }
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
