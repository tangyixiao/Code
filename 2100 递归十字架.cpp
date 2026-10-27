#include <bits/stdc++.h>
using namespace std;
int n, i, j, sz, s;
char b[2200][2200];
void fill(int x, int y, int lv) {
    if (lv == 1) {
        b[x][y] = '*';
        return;
    }
    int s2 = 1;
    for (int t = 1; t < lv - 1; t++) {
        s2 *= 3;
    }
    fill(x, y + s2, lv - 1);
    fill(x + s2, y, lv - 1);
    fill(x + s2, y + s2, lv - 1);
    fill(x + s2, y + 2 * s2, lv - 1);
    fill(x + 2 * s2, y + s2, lv - 1);
}
signed main() {
    scanf("%d", &n);
    sz = 1;
    for (i = 1; i < n; i++) {
        sz *= 3;
    }
    for (i = 0; i < sz; i++) {
        for (j = 0; j < sz; j++) {
            b[i][j] = ' ';
        }
    }
    fill(0, 0, n);
    for (i = 0; i < sz; i++) {
        s = -1;
        for (j = 0; j < sz; j++) {
            if (b[i][j] == '*') {
                s = j;
            }
        }
        for (j = 0; j <= s; j++) {
            putchar(b[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
