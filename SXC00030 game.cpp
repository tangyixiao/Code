#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int T, n, i, k, x;
long long pre[N], best, v;
int a[N];

bool cmp2(int p, int q) {
    return p < q;
}

signed main() {
    scanf("%d", &T);
    while (T > 0) {
        T--;
        scanf("%d %d %d", &n, &k, &x);
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1, cmp2);
        pre[0] = 0;
        for (i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + a[i];
        }
        best = -1e18;
        for (int d = 0; d <= k && d <= n; d++) {
            int m = n - d;
            if (m <= x) {
                v = -pre[m];
            } else {
                v = 2 * pre[m - x] - pre[m];
            }
            if (v > best) {
                best = v;
            }
        }
        printf("%lld\n", best);
    }
    return 0;
}
