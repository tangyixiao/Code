#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;

signed main() {
    scanf("%d", &n);
    for (a = 1; a <= n; a++) {
        for (b = a; b <= n; b++) {
            c = n - a - b;
            if (c >= b) {
                printf("%d=%d+%d+%d\n", n, a, b, c);
            }
        }
    }
    return 0;
}
