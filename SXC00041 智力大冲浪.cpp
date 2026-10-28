#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
int m, n, i, j, k, ans, t[N], b[N], used[N], id[N];
bool cmp(int x, int y) {
    return b[x] > b[y];
}
signed main() {
    if (fopen("riddle.in", "r")) {
        freopen("riddle.in", "r", stdin);
        freopen("riddle.out", "w", stdout);
    }
    scanf("%d%d", &m, &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    for (i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    ans = m;
    for (k = 1; k <= n; k++) {
        i = id[k];
        for (j = t[i]; j >= 1; j--) {
            if (!used[j]) {
                used[j] = 1;
                break;
            }
        }
        if (j < 1) {
            ans -= b[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
