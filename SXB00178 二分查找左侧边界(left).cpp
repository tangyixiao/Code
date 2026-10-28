#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, i, x, l, r, mid, a[N];
signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d", &x);
        l = 1, r = n + 1;
        for (; l < r;) {
            mid = (l + r) >> 1;
            if (a[mid] < x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l > n || a[l] != x) {
            l = -1;
        }
        if (i > 1) {
            printf(" ");
        }
        printf("%d", l);
    }
    printf("\n");
    return 0;
}
