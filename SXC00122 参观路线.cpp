#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 2e5 + 5;
int n, m, ec, hd = 1;
int head[N], nxt[M], to[M], vis[M];
int stk[M], ans[M];
int w[N];

void add(int u, int v) {
    ec++;
    to[ec] = v;
    nxt[ec] = head[u];
    head[u] = ec;
}

signed main() {
    cin >> n >> m;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    long long res = sum - (long long)n * (n + 1) / 2 - m;
    int top = 0, cnt = 0;
    stk[++top] = 1;
    while (top > 0) {
        int u = stk[top];
        int e = head[u];
        for (; e != 0 && vis[e];) {
            e = nxt[e];
        }
        head[u] = e;
        if (e == 0) {
            ans[++cnt] = u;
            top--;
        } else {
            vis[e] = 1;
            vis[e ^ 1] = 1;
            stk[++top] = to[e];
        }
    }
    cout << res << "\n";
    cout << cnt - 1 << "\n";
    for (int i = cnt; i >= 1; i--) {
        cout << ans[i];
        if (i > 1) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
