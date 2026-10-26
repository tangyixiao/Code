#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, i, j, ans;
int x[N], y[N];
signed main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    for (i = 1; i <= m; i++) {
        scanf("%d", &y[i]);
    }
    sort(x + 1, x + n + 1), sort(y + 1, y + m + 1);
    ans = 2e9 + 5;
    i = 1, j = 1;
    for (; i <= n && j <= m;) {
        ans = min(ans, abs(x[i] - y[j]));
        if (x[i] < y[j]) {
            i++;
        } else {
            j++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
