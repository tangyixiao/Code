#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, i, x;
int a[N];

signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    while (m > 0) {
        m--;
        scanf("%d", &x);
        int p = lower_bound(a + 1, a + n + 1, x) - a;
        if (p == 1) {
            printf("%d\n", a[1]);
        } else if (p > n) {
            printf("%d\n", a[n]);
        } else {
            int d1 = a[p] - x;
            int d2 = x - a[p - 1];
            if (d2 <= d1) {
                printf("%d\n", a[p - 1]);
            } else {
                printf("%d\n", a[p]);
            }
        }
    }
    return 0;
}
