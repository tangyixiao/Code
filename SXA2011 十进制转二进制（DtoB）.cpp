#include <bits/stdc++.h>
using namespace std;
long long n;
signed main() {
    scanf("%lld", &n);
    if (n == 0) {
        printf("0");
    }
    for (; n > 0;) {
        printf("%d", (int)(n % 2));
        n /= 2;
    }
    printf("\n");
    return 0;
}
