#include <bits/stdc++.h>
using namespace std;
int n, h, l, s;
signed main() {
    scanf("%d", &n);
    h = n / 1000, l = n % 1000;
    if (h < l) {
        s = h, h = l, l = s;
    }
    printf("%d\n", h * 1000 + l);
    return 0;
}
