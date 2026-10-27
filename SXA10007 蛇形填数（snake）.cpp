#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n;
long long a[N][N];

signed main() {
    cin >> n;
    int x = 1, y = n, c = 1;
    a[x][y] = 1;
    while (c < n * n) {
        while (x + 1 <= n && a[x + 1][y] == 0) {
            a[++x][y] = ++c;
        }
        while (y - 1 >= 1 && a[x][y - 1] == 0) {
            a[x][--y] = ++c;
        }
        while (x - 1 >= 1 && a[x - 1][y] == 0) {
            a[--x][y] = ++c;
        }
        while (y + 1 <= n && a[x][y + 1] == 0) {
            a[x][++y] = ++c;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%6lld", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
