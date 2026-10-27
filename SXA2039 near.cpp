#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, t, i, x;
int a[N];

signed main() {
    scanf("%d %d", &n, &t);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    while (t > 0) {
        t--;
        scanf("%d", &x);
        int p = lower_bound(a + 1, a + n + 1, x) - a;
        int best = 0;
        long long bd = -1;
        if (p <= n) {
            bd = a[p] - x;
            best = a[p];
        }
        if (p > 1) {
            long long d = x - a[p - 1];
            if (bd < 0 || d <= bd) {
                bd = d;
                best = a[p - 1];
            }
        }
        int cnt = upper_bound(a + 1, a + n + 1, best) - lower_bound(a + 1, a + n + 1, best);
        printf("%d\n", cnt);
    }
    return 0;
}
