#include <bits/stdc++.h>
using namespace std;
int n, m, i, x, all;
int v[1005];
signed main() {
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        v[x] = 1;
    }
    all = 1;
    for (i = 0; i < n; i++) {
        if (v[i] == 0) {
            all = 0;
        }
    }
    if (all == 1) {
        printf("%d\n", n);
        return 0;
    }
    int f = 0;
    for (i = 0; i < n; i++) {
        if (v[i] == 0) {
            if (f) {
                printf(" ");
            }
            printf("%d", i);
            f = 1;
        }
    }
    printf("\n");
    return 0;
}
