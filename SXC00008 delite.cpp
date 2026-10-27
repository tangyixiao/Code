#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e9;

int n, i, j, k, tot;
int bx[N], by[N];

signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &bx[i], &by[i]);
    }
    long long ans = 0;
    for (i = 1; i <= n; i++) {
        int u = i;
        int v = (i == n) ? 1 : i + 1;
        ans += abs(bx[u] - bx[v]) + abs(by[u] - by[v]);
    }
    printf("%lld\n", ans);
    return 0;
}
