#include <bits/stdc++.h>
using namespace std;
int i, a[4], mn;
signed main() {
    for (i = 0; i < 4; i++) {
        scanf("%d", &a[i]);
    }
    mn = a[0];
    for (i = 1; i < 4; i++) {
        if (a[i] < mn) {
            mn = a[i];
        }
    }
    printf("%d\n", mn);
    return 0;
}
