#include <bits/stdc++.h>
using namespace std;

char a[205], c[205], q[205];
int b, ql, cl;
int x[210], y[210], z[215];

signed main() {
    scanf("%s", a);
    scanf("%d", &b);
    scanf("%s", c);
    long long rem = 0;
    ql = 0;
    for (int i = 0; a[i]; i++) {
        rem = rem * 10 + (a[i] - '0');
        int d = rem / b;
        rem %= b;
        if (ql > 0 || d > 0) {
            q[ql++] = '0' + d;
        }
    }
    if (ql == 0) {
        q[ql++] = '0';
    }
    cl = strlen(c);
    for (int i = 0; i < ql; i++) {
        x[ql - 1 - i] = q[i] - '0';
    }
    for (int i = 0; i < cl; i++) {
        y[cl - 1 - i] = c[i] - '0';
    }
    int L = ql > cl ? ql : cl;
    int carry = 0;
    for (int i = 0; i < L; i++) {
        int s = carry;
        if (i < ql) {
            s += x[i];
        }
        if (i < cl) {
            s += y[i];
        }
        z[i] = s % 10;
        carry = s / 10;
    }
    int rl = L;
    if (carry > 0) {
        z[rl++] = carry;
    }
    for (int i = rl - 1; i >= 0; i--) {
        printf("%d", z[i]);
    }
    printf("\n");
    return 0;
}
