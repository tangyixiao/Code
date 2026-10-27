#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, rt, tot, t, h, tl, ct;
int fa[N], a[N], hd[N], nx[N], s[N], in[N], q[N], c[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> fa[i] >> a[i];
        if (fa[i] == 0) {
            rt = i;
        } else {
            nx[i] = hd[fa[i]];
            hd[fa[i]] = i;
        }
    }
    q[tl++] = rt;
    for (; h < tl;) {
        int u = q[h++];
        for (int v = hd[u]; v; v = nx[v]) {
            q[tl++] = v;
        }
    }
    for (int i = 1; i <= n; i++) {
        s[i] = a[i];
    }
    for (int i = tl - 1; i > 0; i--) {
        s[fa[q[i]]] += s[q[i]];
    }
    tot = s[rt];
    if (n < 3 || ((tot % 3) + 3) % 3 != 0) {
        cout << -1 << "\n";
        return 0;
    }
    t = tot / 3;
    for (int i = 1; i <= n; i++) {
        if (i != rt && s[i] == t) {
            c[i] = 1;
        }
    }
    for (int i = tl - 1; i > 0; i--) {
        int u = q[i];
        in[fa[u]] += c[u] + in[u];
    }
    int p = 0, r1 = 0, r2 = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] && in[i] == 0) {
            p++;
            if (p == 1) {
                r1 = i;
            } else if (p == 2) {
                r2 = i;
            }
        }
    }
    if (p < 2) {
        cout << -1 << "\n";
        return 0;
    }
    if (r1 > r2) {
        int z = r1;
        r1 = r2;
        r2 = z;
    }
    cout << r1 << " " << r2 << "\n";
    return 0;
}
