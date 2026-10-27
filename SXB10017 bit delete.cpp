#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i, c0, c1;
char s[N];

signed main() {
    scanf("%s", s);
    c0 = 0;
    c1 = 0;
    for (i = 0; s[i]; i++) {
        if (s[i] == '0') {
            c0++;
        } else {
            c1++;
        }
    }
    if (c0 == c1) {
        printf("0\n");
    } else if (c0 < c1) {
        printf("%d\n", c0);
    } else {
        printf("%d\n", c1);
    }
    return 0;
}
