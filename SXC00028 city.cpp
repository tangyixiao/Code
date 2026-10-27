#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;
int n, lo, hi, nlc, lc, bn;
long long bs, imp[N];
int eu[N], ev[N], ew[N], ord[N], fa[N], sz[N], loc[N], lp[M];
int lhd[M], lto[M], lnx[M], par[M], rt[M], qq[M], vis[M], sum[M];
int ae[M], be[M];

int find(int x) {
    for (; fa[x] != x;) {
        fa[x] = fa[fa[x]];
        x = fa[x];
    }
    return x;
}

bool cmp(int a, int b) {
    return ew[a] < ew[b];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        cin >> eu[i] >> ev[i] >> ew[i];
        ord[i] = i;
    }
    sort(ord + 1, ord + n, cmp);
    for (lo = 1; lo < n;) {
        for (hi = lo; hi < n && ew[ord[hi]] == ew[ord[lo]]; hi++) {
        }
        nlc = 0;
        lc = 0;
        for (int t = lo; t < hi; t++) {
            int e = ord[t], a = find(eu[e]), b = find(ev[e]);
            if (loc[a] == 0) {
                loc[a] = ++nlc;
                lp[nlc] = a;
                sum[nlc] = sz[a];
                vis[nlc] = 0;
                lhd[nlc] = 0;
            }
            if (loc[b] == 0) {
                loc[b] = ++nlc;
                lp[nlc] = b;
                sum[nlc] = sz[b];
                vis[nlc] = 0;
                lhd[nlc] = 0;
            }
            ae[t] = loc[a];
            be[t] = loc[b];
            lto[++lc] = loc[b];
            lnx[lc] = lhd[loc[a]];
            lhd[loc[a]] = lc;
            lto[++lc] = loc[a];
            lnx[lc] = lhd[loc[b]];
            lhd[loc[b]] = lc;
        }
        int qh = 0, qt = 0;
        for (int i = 1; i <= nlc; i++) {
            if (vis[i]) {
                continue;
            }
            vis[i] = 1;
            par[i] = 0;
            rt[i] = i;
            qq[qt++] = i;
            for (; qh < qt;) {
                int u = qq[qh++];
                for (int t = lhd[u]; t; t = lnx[t]) {
                    int v = lto[t];
                    if (vis[v]) {
                        continue;
                    }
                    vis[v] = 1;
                    par[v] = u;
                    rt[v] = i;
                    qq[qt++] = v;
                }
            }
        }
        for (int i = qt - 1; i > 0; i--) {
            int u = qq[i];
            if (par[u]) {
                sum[par[u]] += sum[u];
            }
        }
        for (int t = lo; t < hi; t++) {
            int e = ord[t], a = ae[t], b = be[t], c;
            if (par[a] == b) {
                c = a;
            } else {
                c = b;
            }
            long long p = sum[c], q = sum[rt[c]] - p;
            imp[e] = 2LL * p * q;
        }
        for (int t = lo; t < hi; t++) {
            int e = ord[t], a = find(eu[e]), b = find(ev[e]);
            if (a != b) {
                fa[b] = a;
                sz[a] += sz[b];
            }
        }
        for (int i = 1; i <= nlc; i++) {
            loc[lp[i]] = 0;
        }
        lo = hi;
    }
    bs = 0;
    bn = 0;
    for (int i = 1; i < n; i++) {
        if (imp[i] > bs) {
            bs = imp[i];
        }
    }
    for (int i = 1; i < n; i++) {
        if (imp[i] == bs) {
            bn++;
        }
    }
    cout << bs << " " << bn << "\n";
    int f = 1;
    for (int i = 1; i < n; i++) {
        if (imp[i] != bs) {
            continue;
        }
        if (!f) {
            cout << " ";
        }
        f = 0;
        cout << i;
    }
    cout << "\n";
    return 0;
}
