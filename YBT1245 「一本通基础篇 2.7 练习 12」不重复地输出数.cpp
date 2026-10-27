#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i, a[N], b[N];

signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int t = 0;
    for (i = 1; i <= n; i++) {
        if (i == 1 || a[i] != a[i - 1]) {
            t++;
            b[t] = a[i];
        }
    }
    for (i = 1; i <= t; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}
