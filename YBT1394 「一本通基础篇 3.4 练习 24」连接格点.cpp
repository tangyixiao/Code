#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 1e6 + 5;
int m, n, i, x1, x2, y1, y2, a, b, c, ans, fa[N], tot;
int find(int x) {
    for (; fa[x] != x;) {
        fa[x] = fa[fa[x]], x = fa[x];
    }
    return x;
}
int id(int x, int y) {
    return (x - 1) * n + y;
}
signed main() {
    scanf("%d%d", &m, &n);
    tot = m * n;
    for (i = 1; i <= tot; i++) {
        fa[i] = i;
    }
    for (; scanf("%d%d%d%d", &x1, &y1, &x2, &y2) == 4;) {
        a = find(id(x1, y1)), b = find(id(x2, y2));
        if (a != b) {
            fa[a] = b;
        }
    }
    for (i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + 1 <= m) {
                a = find(id(i, j)), b = find(id(i + 1, j));
                if (a != b) {
                    fa[a] = b, ans += 1;
                }
            }
        }
    }
    for (i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j + 1 <= n) {
                a = find(id(i, j)), b = find(id(i, j + 1));
                if (a != b) {
                    fa[a] = b, ans += 2;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
