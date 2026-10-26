#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, M = 5e4 + 5;
int n, m, ec, ord[N];
int head[N], nxt[M], to[M], din[N];
int head2[N], nxt2[M], to2[M];
long long wi[N], wo[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        nxt[i] = head[x], to[i] = y, head[x] = i;
        nxt2[i] = head2[y], to2[i] = x, head2[y] = i;
        din[y]++;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (din[i] == 0) {
            wi[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        ord[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        c = i;
        for (int e = head[c]; e; e = nxt[e]) {
            wi[to[e]] += wi[c];
        }
    }
    wo[n] = 1;
    for (int i = n; i >= 1; i--) {
        c = i;
        for (int e = head2[c]; e; e = nxt2[e]) {
            wo[to2[e]] += wo[c];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = max(ans, wi[to2[i]] * wo[to[i]]);
    }
    cout << ans << "\n";
    return 0;
}
