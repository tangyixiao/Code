#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, i, d, ok;
long long a[N], x;
signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (i = 1; i < n; i++) {
        d = abs(a[i + 1] - a[i]);
        if (d >= 1 && d <= n - 1) {
            ok |= 1 << d;
        }
    }
    for (i = 1; i <= n - 1; i++) {
        if (!((ok >> i) & 1)) {
            printf("Not Jolly\n");
            return 0;
        }
    }
    printf("Jolly\n");
    return 0;
}
