#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, i, j, c;
int a[N], b[N];
bool cmp(int x, int y) {
    return x < y;
}
signed main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + m + 1, cmp);
    c = 0;
    j = 1;
    for (i = 1; i <= m; i++) {
        for (; j <= n && a[j] < b[i]; j++) {
        }
        if (j <= n && a[j] == b[i]) {
            if (c) {
                printf(" ");
            }
            printf("%d", b[i]);
            c = 1;
        }
    }
    printf("\n");
    return 0;
}
