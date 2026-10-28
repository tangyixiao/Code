#include <bits/stdc++.h>
using namespace std;

const int M = 1e4 + 5;
int n, m, v;
long long f[M];

signed main() {
    if (fopen("numcb.in", "r")) {
        freopen("numcb.in", "r", stdin);
        freopen("numcb.out", "w", stdout);
    }
    scanf("%d%d", &n, &m);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v);
        if (v > m) {
            continue;
        }
        for (int s = m; s >= v; s--) {
            f[s] += f[s - v];
        }
    }
    printf("%lld\n", f[m]);
    return 0;
}
