#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 16;
int st, tg, q[N], pre[N], pm[N], eu[32], ev[32], pa[N], np, ne, cnt;

inline void input() {
    char c;
    int b = 0, t = 0;
    for (int i = 0; i < 16; i++) {
        cin >> c;
        if (c == '1') {
            b |= 1 << i;
        }
    }
    for (int i = 0; i < 16; i++) {
        cin >> c;
        if (c == '1') {
            t |= 1 << i;
        }
    }
    st = b, tg = t;
    for (int p = 0; p < 16; p++) {
        if (p % 4 < 3) {
            eu[ne] = p, ev[ne++] = p + 1;
        }
        if (p / 4 < 3) {
            eu[ne] = p, ev[ne++] = p + 4;
        }
    }
}

inline void solve() {
    pre[st] = -1;
    q[cnt++] = st;
    for (int h = 0; h < cnt && pre[tg] == 0 && tg != st; h++) {
        int u = q[h];
        for (int i = 0; i < ne; i++) {
            int p = eu[i], v = ev[i];
            if (((u >> p) & 1) == ((u >> v) & 1)) {
                continue;
            }
            int r = u ^ (1 << p) ^ (1 << v);
            if (pre[r]) {
                continue;
            }
            pre[r] = u, pm[r] = i, q[cnt++] = r;
        }
    }
    for (int u = tg; pre[u] != -1; u = pre[u]) {
        pa[np++] = u;
    }
    cout << np << "\n";
    for (int i = np - 1; i >= 0; i--) {
        int u = pa[i];
        int p = eu[pm[u]], v = ev[pm[u]];
        if (p > v) {
            swap(p, v);
        }
        cout << p / 4 + 1 << p % 4 + 1 << v / 4 + 1 << v % 4 + 1 << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
