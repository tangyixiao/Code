#include <bits/stdc++.h>
using namespace std;
int n, i, j, t, d[5];
bool cmp(int x, int y) {
    return x > y;
}
signed main() {
    scanf("%d", &n);
    d[1] = n / 100, d[2] = n / 10 % 10, d[3] = n % 10;
    sort(d + 1, d + 4, cmp);
    printf("%d%d%d\n", d[1], d[2], d[3]);
    return 0;
}
