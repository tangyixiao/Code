#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char a[N], b[N], c[N];
int n, la, lb, i, j, t, v, f;
int dg(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    return ch - 'A' + 10;
}
char ch(int v) {
    if (v < 10) {
        return (char)('0' + v);
    }
    return (char)('A' + v - 10);
}
int cmp() {
    if (la != lb) {
        return la > lb ? 1 : -1;
    }
    for (i = 0; i < la; i++) {
        if (a[i] != b[i]) {
            return a[i] > b[i] ? 1 : -1;
        }
    }
    return 0;
}
signed main() {
    scanf("%d%s%s", &n, a, b);
    la = strlen(a), lb = strlen(b);
    f = cmp();
    if (f == 0) {
        printf("0\n");
        return 0;
    }
    if (f < 0) {
        printf("-");
        strcpy(c, a);
        strcpy(a, b);
        strcpy(b, c);
        t = la, la = lb, lb = t;
    }
    j = 0;
    for (i = la - 1; i >= 0; i--) {
        v = dg(a[i]);
        if (i - (la - lb) >= 0) {
            v -= dg(b[i - (la - lb)]);
        }
        if (j) {
            v--;
        }
        if (v < 0) {
            v += n, j = 1;
        } else {
            j = 0;
        }
        c[la - 1 - i] = ch(v);
    }
    t = la;
    while (t > 1 && c[t - 1] == '0') {
        t--;
    }
    for (i = t - 1; i >= 0; i--) {
        putchar(c[i]);
    }
    putchar('\n');
    return 0;
}
