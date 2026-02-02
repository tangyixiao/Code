#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
int n, p, a[N][N];
void dfs(int x, int l, int q) {
    if (x == 2) {
        a[l][q] = 0;
        return;
    }
    for (int i = l; i <= l + x / 2 - 1; i++) {
        for (int j = q; j <= q + x / 2 - 1; j++) {
            a[i][j] = 0;
        }
    }

    dfs(x / 2, l + x / 2, q);
    dfs(x / 2, l + x / 2, q + x / 2);
    dfs(x / 2, l, q + x / 2);
}
signed main() {
    scanf("%d", &n);
    p = 1 << n;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) {
            a[i][j] = 1;
        }
    }

    dfs(p, 1, 1);
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
