#include <bits/stdc++.h>
using namespace std;

int a, b, c;

signed main() {
    scanf("%d %d %d", &a, &b, &c);
    if (a >= 90 || b >= 90 || c >= 90) {
        printf("beijing\n");
    } else {
        printf("nanjing\n");
    }
    return 0;
}
