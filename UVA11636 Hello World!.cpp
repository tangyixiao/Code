#include <bits/stdc++.h>

signed main() {
    int n, count = 1;
    while (scanf("%d", &n) == 1 && n >= 0) {
        printf("Case %d: %d\n", count, (int)ceil(log2(n)));
        count++;
    }
    return 0;
}
