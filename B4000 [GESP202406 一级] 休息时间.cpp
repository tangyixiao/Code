#include <bits/stdc++.h>
using namespace std;
int h, m, s, k;
signed main() {
    scanf("%d%d%d%d", &h, &m, &s, &k);
    s += k;
    m += s / 60;
    s = s % 60;
    h += m / 60;
    m = m % 60;
    printf("%d %d %d", h, m, s);
    return 0;
}