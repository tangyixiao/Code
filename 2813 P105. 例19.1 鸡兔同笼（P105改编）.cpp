#include <bits/stdc++.h>
using namespace std;

int a;

signed main() {
    scanf("%d", &a);
    if (a % 2 != 0) {
        printf("0 0\n");
        return 0;
    }
    int mn = a / 4 + (a % 4) / 2;
    int mx = a / 2;
    printf("%d %d\n", mn, mx);
    return 0;
}
