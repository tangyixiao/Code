#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
int T, n, dep[N], vis[N], b[N], ok, ji[N], ou[N];
vector<int> p[N];
void dfs(int x, int deep) {
    dep[x] = deep;
    for (int i = 0; i < p[x].size(); ++i) {
        int to = p[x][i];
        if (to == 1 || dep[to])
            continue;
        dfs(to, deep + 1);
    }
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(dep, 0, sizeof(dep));
        memset(ji, 0, sizeof(ji));
        memset(ou, 0, sizeof(ou));
        for (int i = 1; i <= n; ++i)
            p[i].clear();
        for (int i = 1, u, v; i < n; ++i) {
            scanf("%d%d", &u, &v);
            p[u].push_back(v);
            p[v].push_back(u);
        }
        dfs(1, 0);
        int j = 0, o = 0;
        for (int i = 1; i <= n; ++i)
            if (dep[i] & 1)
                ++j, ji[j] = i;
            else
                ++o, ou[o] = i;
        if (abs(j - o) > 1)
            puts("-1");
        else if (j > o) {
            o = j = 0;
            for (int i = 1; i <= n; ++i) {
                if (i & 1)
                    printf("%d ", ji[++j]);
                else
                    printf("%d ", ou[++o]);
            }
            puts("");
        } else {
            o = j = 0;
            for (int i = 1; i <= n; ++i) {
                if (!(i & 1))
                    printf("%d ", ji[++j]);
                else
                    printf("%d ", ou[++o]);
            }
            puts("");
        }
    }
    return 0;
}
