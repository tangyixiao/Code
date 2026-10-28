#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
bitset<N> r[N];
int n, m, i, j, k, x, y;
long long ans;

signed main() {
    freopen("rank.in", "r", stdin);
    freopen("rank.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        r[x][y] = 1;
    }
    for (k = 1; k <= n; k++) {
        if (r[k].any()) {
            for (i = 1; i <= n; i++) {
                if (r[i][k]) {
                    r[i] |= r[k];
                }
            }
        }
    }
    ans = 0;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (r[i][j] == 0 && r[j][i] == 0) {
                ans++;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
