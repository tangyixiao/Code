#include <bits/stdc++.h>
using namespace std;
int need, n, power, vi, pi, i, j, k, f[11000];
bool z;
int main() {
    scanf("%d%d%d", &need, &n, &power);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &vi, &pi);
        for (j = power; j >= pi; j--) {
            f[j] = max(f[j], f[j - pi] + vi);
        }
    }
    for (j = 0; j <= power; j++) {
        if (f[j] >= need) {
            k = j;
            z = true;
            break;
        }
    }
    if (!z) {
        printf("Impossible");
    } else {
        printf("%d", power - k);
    }
    return 0;
}