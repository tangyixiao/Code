#include <bits/stdc++.h>
using namespace std;
const int N = 9, M = 10;
int a[M][M];
bool r[M][M], c[M][M], p[M][M];
inline void print() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    exit(0);
}
inline void dfs(int x, int y) {
    if (a[x][y]) {
        if (x == N && y == N) {
            print();
        } else {
            if (y == N) {
                dfs(x + 1, 1);

            } else {
                dfs(x, y + 1);
            }
        }
    } else {
        for (int i = 1; i <= N; i++) {
            if (!r[x][i] && !c[y][i] && !p[(x - 1) / 3 * 3 + ((y - 1) / 3) + 1][i]) {
                a[x][y] = i;
                r[x][i] = true;
                c[y][i] = true;
                p[(x - 1) / 3 * 3 + ((y - 1) / 3) + 1][i] = true;
                if (x == N && y == N) {
                    print();
                } else {
                    if (y == N) {
                        dfs(x + 1, 1);
                    } else {
                        dfs(x, y + 1);
                    }
                }
                r[x][i] = false;
                c[y][i] = false;
                p[(x - 1) / 3 * 3 + ((y - 1) / 3) + 1][i] = false;
                a[x][y] = 0;
            }
        }
    }
    return;
}
signed main() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j]) {
                r[i][a[i][j]] = true;
                c[j][a[i][j]] = true;
                p[(i - 1) / 3 * 3 + ((j - 1) / 3) + 1][a[i][j]] = true;
            }
        }
    }
    dfs(1, 1);
    return 0;
}