#include <bits/stdc++.h>
using namespace std;
int n, i, x, ans;
signed main() {
    scanf("%d", &n);
    ans = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        ans |= x;
    }
    printf("%d\n", ans);
    return 0;
}
