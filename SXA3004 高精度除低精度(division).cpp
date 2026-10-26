#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
char s[N];
long long m, r, q;
int i, len, st;
signed main() {
    scanf("%s", s + 1);
    scanf("%lld", &m);
    len = strlen(s + 1), r = 0, st = 0;
    for (i = 1; i <= len; i++) {
        r = r * 10 + (s[i] - '0');
        q = r / m;
        r %= m;
        if (q || st) {
            printf("%lld", q);
            st = 1;
        }
    }
    if (!st) {
        printf("0");
    }
    printf("\n%lld\n", r);
    return 0;
}
