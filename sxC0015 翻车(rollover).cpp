#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, m, i, x, g, f;
int a[N], hd[N], nx[N], c[N];
signed main() {
    scanf("%d %d %d", &n, &k, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        g = a[i] % m;
        if (hd[g] == 0) {
            hd[g] = i;
        } else {
            nx[i] = hd[g];
            hd[g] = i;
        }
        c[g]++;
    }
    int pick = -1;
    for (i = 0; i < m; i++) {
        if (c[i] >= k) {
            pick = i;
            break;
        }
    }
    if (pick < 0) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    f = 0;
    int t = hd[pick];
    for (i = 0; i < k; i++) {
        if (f) {
            printf(" ");
        }
        printf("%d", a[t]);
        f = 1;
        t = nx[t];
    }
    printf("\n");
    return 0;
}
