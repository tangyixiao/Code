#include <bits/stdc++.h>
using namespace std;

int n, i, j, c;

signed main() {
    scanf("%d", &n);
    c = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            putchar('A' + c % 26);
            c++;
        }
        printf("\n");
    }
    return 0;
}
