#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, t, i, j, s, u;
double ans;
int cnt[N], val[N], id[N];
bool cmp(int a, int b) {
    return (double)val[a] / cnt[a] > (double)val[b] / cnt[b];
}
signed main() {
    scanf("%d %d", &n, &t);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &cnt[i], &val[i]);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    ans = 0;
    for (i = 1; i <= n; i++) {
        if (t <= 0) {
            break;
        }
        u = id[i];
        if (cnt[u] <= t) {
            ans += val[u];
            t -= cnt[u];
        } else {
            ans += (double)t * val[u] / cnt[u];
            t = 0;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
