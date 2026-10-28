#include <bits/stdc++.h>
using namespace std;

int x;

signed main() {
    scanf("%d", &x);
    if (x / 100 == x % 10) {
        printf("Y\n");
    } else {
        printf("N\n");
    }
    return 0;
}
