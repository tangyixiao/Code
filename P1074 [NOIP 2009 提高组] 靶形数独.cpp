#include <bits/stdc++.h>
using namespace std;
const int N = 10, inf = 0x3f3f3f3f;
struct f {
    int rank, sum;
} cou[N];
bool operator<(const f &a, const f &b) { return a.sum < b.sum; }
bool r[10][10], c[10][10], g[10][10];
int a[10][10], s[100][4], u, ok, ans = -1, filled;
int palace(int y) {
    if (y <= 3) {
        return 1;
    } else if (y <= 6) {
        return 2;
    } else {
        return 3;
    }
}
int which(int x, int y) {
    if (x <= 3) {
        return palace(y);
    } else if (x <= 6) {
        return 3 + palace(y);
    } else {
        return 6 + palace(y);
    }
}

int point(int x, int y) {
    if (x == 1 || y == 1 || x == 9 || y == 9) {
        return 6;
    }
    if (x == 2 || y == 2 || x == 8 || y == 8) {
        return 7;
    }
    if (x == 3 || y == 3 || x == 7 || y == 7) {
        return 8;
    }
    if (x == 4 || y == 4 || x == 6 || y == 6) {
        return 9;
    }
    if (x == 5 && y == 5) {
        return 10;
    }
}
inline void dfs(int p, int score) {
    if (p == u) {
        ans = max(ans, score);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (r[s[p][0]][i] || c[s[p][1]][i] || g[s[p][3]][i]) {
            continue;
        }
        r[s[p][0]][i] = c[s[p][1]][i] = g[s[p][3]][i] = true;
        dfs(p + 1, score + (s[p][2] * i));
        r[s[p][0]][i] = c[s[p][1]][i] = g[s[p][3]][i] = false;
    }
    return;
}
inline void init() {
    for (int i = 1; i <= 9; i++) {
        cou[i].rank = i;
    }
    return;
}
signed main() {
    init();
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] > 0) {
                r[i][a[i][j]] = c[j][a[i][j]] = g[which(i, j)][a[i][j]] = true;
                filled += a[i][j] * point(i, j);
            } else {
                cou[i].sum++;
            }
        }
    }
    sort(cou + 1, cou + 10);
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (a[cou[i].rank][j] == 0) {
                s[u][0] = cou[i].rank;
                s[u][1] = j;
                s[u][2] = point(cou[i].rank, j);
                s[u++][3] = which(cou[i].rank, j);
            }
        }
    }
    dfs(0, filled);
    printf("%d\n", ans);
    return 0;
}