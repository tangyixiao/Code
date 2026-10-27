#include <bits/stdc++.h>
using namespace std;
int n, r, a, b, c;
signed main() {
    scanf("%d", &n);
    r = (n / 1000) + (n / 100 % 10) * 10 + (n / 10 % 10) * 100 + (n % 10) * 1000;
    if (r >= n) {
        a = r;
        b = n;
    } else {
        a = n;
        b = r;
    }
    c = a - b;
    printf("%d-%d=%d\n", a, b, c);
    return 0;
}
