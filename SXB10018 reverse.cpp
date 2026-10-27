#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, i, j, k, p[N], pos[N];
signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    k = 0;
    for (i = 1; i <= n; i++) {
        if (p[i] != i) {
            k = i;
            break;
        }
    }
    if (k) {
        j = pos[k];
        for (; k < j; k++, j--) {
            swap(p[k], p[j]);
        }
    }
    for (i = 1; i <= n; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", p[i]);
    }
    printf("\n");
    return 0;
}
