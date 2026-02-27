#include <bits/stdc++.h>
using namespace std;
int x, y, z, t;
signed main() {
    scanf("%d%d%d%d", &x, &y, &z, &t);
    if (2 * x + 5 * y + 3 * z <= t) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("%d", abs(t - (2 * x + 5 * y + 3 * z)));
    return 0;
}