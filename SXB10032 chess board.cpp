#include <bits/stdc++.h>
using namespace std;

int n, k, i, j, cnt;
char s[16][16];
int col[16];

void dfs(int r, int put) {
    if (put == k) {
        cnt++;
        return;
    }
    if (r > n) {
        return;
    }
    for (int c = 1; c <= n; c++) {
        if (s[r][c] == '#' && col[c] == 0) {
            col[c] = 1;
            dfs(r + 1, put + 1);
            col[c] = 0;
        }
    }
    dfs(r + 1, put);
}

signed main() {
    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    cnt = 0;
    dfs(1, 0);
    printf("%d\n", cnt);
    return 0;
}
