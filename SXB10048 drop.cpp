#include <bits/stdc++.h>
using namespace std;
int D, I, k, d;
signed main() {
    if (fopen("drop.in", "r")) {
        freopen("drop.in", "r", stdin);
        freopen("drop.out", "w", stdout);
    }
    scanf("%d%d", &D, &I);
    k = 1;
    for (d = 1; d < D; d++) {
        if (I % 2 == 1) {
            I = I / 2 + 1, k = 2 * k;
        } else {
            I = I / 2, k = 2 * k + 1;
        }
    }
    printf("%d\n", k);
    return 0;
}
