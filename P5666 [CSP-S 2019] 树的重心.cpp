#include <bits/stdc++.h>
using namespace std;

int n, head[20005], nxt[40005], pnt[40005], E = 0, ans = (1 << 29), son[20005], ans2;

void add_edge(int u, int v) {
    pnt[E] = v;
    nxt[E] = head[u];
    head[u] = E++;
}

void dfs(int u, int fa) {
    int balance = -1;
    son[u] = 0;
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = pnt[i];
        if (v == fa)
            continue;
        dfs(v, u);
        son[u] += son[v] + 1;
        balance = max(balance, son[v] + 1);
    }
    balance = max(balance, n - son[u] - 1);
    if (balance < ans || (ans == balance && u < ans2)) {
        ans = balance;
        ans2 = u;
    }
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    printf("%d\n", ans2);
    return 0;
}