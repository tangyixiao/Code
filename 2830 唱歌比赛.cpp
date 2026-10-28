#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, i, j;
double s, x, mx, mn, tot;
double sum[N];
int id[N], rk[N];
bool cmp(int x, int y) {
    if (fabs(sum[x] - sum[y]) > 1e-9) {
        return sum[x] > sum[y];
    }
    return x < y;
}
signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        tot = 0, mx = -1e9, mn = 1e9;
        for (j = 1; j <= 10; j++) {
            scanf("%lf", &x);
            tot += x;
            if (x > mx) {
                mx = x;
            }
            if (x < mn) {
                mn = x;
            }
        }
        sum[i] = tot - mx - mn;
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    for (i = 1; i <= n; i++) {
        printf("%d %.1f\n", id[i], sum[id[i]]);
    }
    return 0;
}
