#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MAXM = 5e6 + 5;

int head[MAXN], to[MAXM * 2], nxt[MAXM * 2], tot;
int deg[MAXN];
bool mark[MAXN];

void init(int n) {
    tot = 0;
    for (int i = 0; i < n; i++) {
        head[i] = -1;
        deg[i] = 0;
        mark[i] = false;
    }
}

void add_edge(int u, int v) {
    to[tot] = v;
    nxt[tot] = head[u];
    head[u] = tot++;
}

int main() {
    freopen("void.in", "r", stdin);
    freopen("void.out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        init(n);
        
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--; v--;
            add_edge(u, v);
            add_edge(v, u);
            deg[u]++; deg[v]++;
        }
        
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (deg[i] % 2) {
                u = i;
                break;
            }
        }
        if (u == -1) u = 0;
        
        for (int i = head[u]; i != -1; i = nxt[i]) {
            int v = to[i];
            mark[v] = true;
        }
        
        int v = -1;
        for (int i = 0; i < n; i++) {
            if (i == u) continue;
            int cnt = 0;
            for (int j = head[i]; j != -1; j = nxt[j]) {
                int w = to[j];
                if (mark[w]) cnt++;
            }
            if (cnt % 2 == 0) {
                v = i;
                break;
            }
        }
        
        printf("%d %d\n", u + 1, v + 1);
    }
    return 0;
}