#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = 1e6 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int t, n, m;
int hd[N], hd2[N], to[M], to2[M], nx[M], nx2[M];
long long wt[M];
int ec, ec2;
long long d[N], e[N], ans;
priority_queue<pair<long long, int>, vector<pair<long long, int>>,
               greater<pair<long long, int>>>
    q;

inline void input() {
    cin >> t;
}

inline void dij(int s, int *h, int *tt, int *nn, long long *w, long long *dd,
                int &e) {
    fill(dd + 1, dd + n + 1, INF);
    dd[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().second;
        long long du = q.top().first;
        q.pop();
        if (du > dd[u]) {
            continue;
        }
        for (int i = h[u]; i; i = nn[i]) {
            if (du + w[i] < dd[tt[i]]) {
                dd[tt[i]] = du + w[i];
                q.push({dd[tt[i]], tt[i]});
            }
        }
    }
    (void)e;
    return;
}

inline void solve() {
    for (; t--;) {
        cin >> n >> m;
        fill(hd + 1, hd + n + 1, 0);
        fill(hd2 + 1, hd2 + n + 1, 0);
        ec = ec2 = 0;
        for (int i = 1; i <= m; i++) {
            int x, y;
            long long z;
            cin >> x >> y >> z;
            to[++ec] = y, wt[ec] = z, nx[ec] = hd[x], hd[x] = ec;
            to2[++ec2] = x, wt[ec2] = z, nx2[ec2] = hd2[y], hd2[y] = ec2;
        }
        dij(1, hd, to, nx, wt, d, ec);
        dij(1, hd2, to2, nx2, wt, e, ec2);
        ans = 0;
        for (int v = 2; v <= n; v++) {
            if (d[v] < INF && e[v] < INF) {
                ans += d[v] + e[v];
            }
        }
        cout << ans << "\n";
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
