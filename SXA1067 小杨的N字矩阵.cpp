#include <bits/stdc++.h>
using namespace std;
int m, i, j;
signed main() {
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            if (j == 0 || j == m - 1 || j == i) {
                printf("+");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
