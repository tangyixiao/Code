#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 2e3 + 5, P = 3e3, Q = 1e5;
struct E {
    int v, w, nx;
} e[M];
int n, m, k, cnt, h[N], d[P], vis[P], q[Q];
void add(int a, int b, int c) {
    e[++cnt] = {b, c, h[a]};
    h[a] = cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    memset(d, 0x3f, sizeof d);
    int l = 0, r = 0, s = k + 1;
    d[s] = 0;
    q[r++] = s;
    vis[s] = 1;
    while (l < r) {
        int x = q[l++];
        vis[x] = 0;
        int u = x / (k + 1), j = x % (k + 1);
        for (int i = h[u]; i; i = e[i].nx) {
            int v = e[i].v, y = v * (k + 1) + j;
            if (d[y] > d[x] + e[i].w) {
                d[y] = d[x] + e[i].w;
                if (!vis[y])
                    vis[y] = 1, q[r++] = y;
            }
            if (j < k) {
                y = v * (k + 1) + j + 1;
                if (d[y] > d[x] + e[i].w / 2) {
                    d[y] = d[x] + e[i].w / 2;
                    if (!vis[y])
                        vis[y] = 1, q[r++] = y;
                }
            }
        }
    }
    int ans = 1e9;
    for (int j = 0; j <= k; j++)
        ans = min(ans, d[n * (k + 1) + j]);
    cout << ans;
}