#include <bits/stdc++.h>
using namespace std;

int t, n, i, j;
int a[105];

signed main() {
    scanf("%d", &t);
    while (t > 0) {
        t--;
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        if (n == 1) {
            printf("NO\n");
            continue;
        }
        int ok = 0;
        for (i = 1; i <= n && ok == 0; i++) {
            for (j = i + 1; j <= n; j++) {
                if (__gcd(a[i], a[j]) <= 2) {
                    ok = 1;
                    break;
                }
            }
        }
        if (ok == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
