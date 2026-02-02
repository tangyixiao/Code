#include <bits/stdc++.h>
#define IL inline
#define RI register int
#define maxn 2001
using namespace std;
IL void read(int& x) {
    int f = 1;
    x = 0;
    char s = getchar();
    while (s > '9' || s < '0') {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (s <= '9' && s >= '0') {
        x = x * 10 + s - '0';
        s = getchar();
    }
    x *= f;
}
int res[maxn][maxn], l[maxn][maxn], r[maxn][maxn], up[maxn][maxn];
int n, m, ans1, ans2;
int main() {
    read(n), read(m);
    for (RI i = 1; i <= n; i++)
        for (RI j = 1; j <= m; j++) {
            read(res[i][j]);
            l[i][j] = r[i][j] = j;
            up[i][j] = 1;
        }
    for (RI i = 1; i <= n; i++)
        for (RI j = 2; j <= m; j++)
            if (res[i][j] != res[i][j - 1])
                l[i][j] = l[i][j - 1];  // 预处理左边界
    for (RI i = 1; i <= n; i++)
        for (RI j = m - 1; j > 0; j--)
            if (res[i][j] != res[i][j + 1])
                r[i][j] = r[i][j + 1];  // 预处理右边界
    for (RI i = 1; i <= n; i++)
        for (RI j = 1; j <= m; j++) {
            if (i > 1 && res[i][j] != res[i - 1][j]) {
                l[i][j] = max(l[i][j], l[i - 1][j]);
                r[i][j] = min(r[i][j], r[i - 1][j]);
                up[i][j] = up[i - 1][j] + 1;
            }
            int a = r[i][j] - l[i][j] + 1;  // 横向长度
            int b = min(a, up[i][j]);              // 竖向长度
            // printf("a:%d b:%d\n",a,b);
            ans1 = max(ans1, b * b);         // 正方形
            ans2 = max(ans2, a * up[i][j]);  // 长方形
        }
    printf("%d\n%d", ans1, ans2);
    return 0;
}