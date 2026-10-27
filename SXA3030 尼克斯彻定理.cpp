#include <bits/stdc++.h>
using namespace std;
long long n, i, st;
signed main() {
    scanf("%lld", &n);
    st = n * n - n + 1;
    printf("%lld**3=", n);
    for (i = 0; i < n; i++) {
        if (i) {
            printf("+");
        }
        printf("%lld", st + 2 * i);
    }
    printf("\n");
    return 0;
}
