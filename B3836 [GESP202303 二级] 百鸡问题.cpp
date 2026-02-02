#include <bits/stdc++.h>
using namespace std;
int x, y, z, n, m, ans;
signed main() {
    scanf("%d%d%d%d%d", &x, &y, &z, &n, &m);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m - i; j++) {
            if (i * x + j * y + (m - i - j) * (1 / (double)z) == n) {
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}