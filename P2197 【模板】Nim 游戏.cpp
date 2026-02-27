#include <bits/stdc++.h>
using namespace std;
int T, n, a, ans;
signed main() {
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            ans ^= a;
        }
        if (ans) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}