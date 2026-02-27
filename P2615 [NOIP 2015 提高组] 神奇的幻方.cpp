#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, x, y, a[N][N];
signed main() {
    scanf("%d", &n);
    x = (n + 1) / 2, y = 1;
    a[x][y] = 1;
    for (int i = 2; i <= n * n; i++) {
        if (x != n && y == 1) {
            x++;
            y = n;
        } else if (x == n && y != 1) {
            x = 1;
            y--;
        } else if (x == n && y == 1) {
            y++;
        } else if (x != n && y != 1) {
            if (a[x + 1][y - 1]) {
                y++;
            } else {
                x++;
                y--;
            }
        }
        a[x][y] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    return 0;
}