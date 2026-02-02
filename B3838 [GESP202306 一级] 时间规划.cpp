#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
signed main() {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", (c - a) * 60 + (d - b));
    return 0;
}