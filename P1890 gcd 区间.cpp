#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int LOG[N], bin[15], n, m, a[N], x, y;
int f[N][10];
int gcd(int i, int j) {
    return !j ? i : gcd(j, i % j);
}
int main() {
    scanf("%d%d", &n, &m);
    bin[0] = 1;
    for (int i = 1; i <= 10; ++i)
        bin[i] = bin[i - 1] << 1;
    LOG[0] = -1;
    for (int i = 1; i <= n; ++i)
        LOG[i] = LOG[i >> 1] + 1;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &f[i][0]);
    for (int i = 1; i <= 10; ++i)
        for (int j = 1; j + bin[i] - 1 <= n; ++j)
            f[j][i] = gcd(f[j][i - 1], f[j + bin[i - 1]][i - 1]);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        int lo = LOG[y - x + 1];
        printf("%d\n", gcd(f[x][lo], f[y - bin[lo] + 1][lo]));
    }
    return 0;
}