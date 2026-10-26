#include <bits/stdc++.h>
using namespace std;
int y, m, ans, d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
signed main() {
    scanf("%d%d", &y, &m);
    ans = d[m];
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) {
        ans = 29;
    }
    printf("%d\n", ans);
    return 0;
}
