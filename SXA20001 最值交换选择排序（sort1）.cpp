#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, i, j, k, t, a[N];
signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++) {
        k = i;
        for (j = i + 1; j <= n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        t = a[i], a[i] = a[k], a[k] = t;
        for (j = 1; j <= n; j++) {
            if (j > 1) {
                printf(" ");
            }
            printf("%d", a[j]);
        }
        printf("\n");
    }
    return 0;
}
