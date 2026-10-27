#include <bits/stdc++.h>
using namespace std;
int n;
signed main() {
    scanf("%d", &n);
    if (n % 10 == 0) {
        printf("%d\n", n * 8 / 10);
    } else {
        printf("%d\n", n);
    }
    return 0;
}
