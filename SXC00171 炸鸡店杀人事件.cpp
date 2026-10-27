#include <bits/stdc++.h>
using namespace std;
const int N = 805;
int n, k, i, j, t, lo, hi, mid, ans, c, nv;
int a[N][N], pre[N][N], val[N * N];
int chk(int lim) {
    for (int r = 1; r <= n; r++) {
        for (int q = 1; q <= n; q++) {
            int b = (a[r][q] > lim) ? 1 : 0;
            pre[r][q] = b + pre[r - 1][q] + pre[r][q - 1] - pre[r - 1][q - 1];
        }
    }
    for (int r = k; r <= n; r++) {
        for (int q = k; q <= n; q++) {
            int s = pre[r][q] - pre[r - k][q] - pre[r][q - k] + pre[r - k][q - k];
            if (s <= c) {
                return 1;
            }
        }
    }
    return 0;
}
signed main() {
    scanf("%d %d", &n, &k);
    nv = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            val[nv++] = a[i][j];
        }
    }
    sort(val, val + nv);
    nv = unique(val, val + nv) - val;
    c = k * k / 2;
    lo = 0;
    hi = nv - 1;
    ans = val[nv - 1];
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (chk(val[mid]) == 1) {
            ans = val[mid];
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
