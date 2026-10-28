#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, i, j, p[N], q[N], l[N];
bool cmp(int u, int v) {
    return p[u] < p[v];
}
signed main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &p[i], &q[i]);
        l[i] = i;
    }
    sort(l, l + n, cmp);
    for (i = 1; i < n; i++) {
        if (q[l[i]] > q[l[i - 1]]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
