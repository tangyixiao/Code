#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, i, x, c[N];
signed main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 == 1) {
            c[x]++;
        }
    }
    int first = 1;
    for (i = 1; i <= 100; i++) {
        for (int t = 0; t < c[i]; t++) {
            if (!first) {
                printf(" ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
