#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5, M = 1e5 + 5;
int n, m, ec;
int head[N], nxt[M], to[M];
int head2[N], nxt2[M], to2[M];
int vis[N], q[N];

void add(int u, int v, int *hd, int *nx, int *t) {
    nx[++ec] = hd[u], t[ec] = v, hd[u] = ec;
}

int dfs(int st, int *hd, int *nx, int *t) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    int h = 0, tl = 1, c = 0;
    q[0] = st, vis[st] = 1;
    for (; h < tl;) {
        int u = q[h];
        h++;
        c++;
        for (int e = hd[u]; e; e = nx[e]) {
            int v = t[e];
            if (!vis[v]) {
                vis[v] = 1;
                q[tl++] = v;
            }
        }
    }
    return c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        nxt[++ec] = head[x], to[ec] = y, head[x] = ec;
        nxt2[ec] = head2[y], to2[ec] = x, head2[y] = ec;
    }
    if (dfs(1, head, nxt, to) == n && dfs(1, head2, nxt2, to2) == n) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
