#include <bits/stdc++.h>
using namespace std;
int n, s;
signed main() {
    scanf("%d", &n);
    if (n % 3 == 0) {
        printf("3");
        s = 1;
    }
    if (n % 5 == 0) {
        printf(s ? " 5" : "5");
        s = 1;
    }
    if (n % 7 == 0) {
        printf(s ? " 7" : "7");
        s = 1;
    }
    if (!s) {
        printf("n");
    }
    printf("\n");
    return 0;
}
