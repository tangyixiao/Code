#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, i, t, ta, tb, a[N], b[N], id[N];
bool cmp(int u, int v) {
    int mu = a[u] < b[u] ? 1 : 0, mv = a[v] < b[v] ? 1 : 0;
    if (mu != mv) {
        return mu > mv;
    }
    if (mu) {
        return a[u] < a[v];
    }
    return b[u] > b[v];
}
signed main() {
    if (fopen("prod.in", "r")) {
        freopen("prod.in", "r", stdin);
        freopen("prod.out", "w", stdout);
    }
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (i = 1; i <= n; i++) {
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    ta = 0, tb = 0;
    for (i = 1; i <= n; i++) {
        t = id[i];
        ta += a[t];
        if (ta > tb) {
            tb = ta;
        }
        tb += b[t];
    }
    printf("%d\n", tb);
    for (i = 1; i <= n; i++) {
        printf("%d", id[i]);
        if (i < n) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
