#include <bits/stdc++.h>
using namespace std;
int n, i, j, d, v;
signed main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            d = min(min(i, j), min(n - 1 - i, n - 1 - j));
            v = (n + 1) / 2 - d;
            printf("%2d", v);
        }
        printf("\n");
    }
    return 0;
}
