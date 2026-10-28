#include <bits/stdc++.h>
using namespace std;
const int N = 4e2 + 5;
char a[N], b[N], c[N];
int p[N], q[N], r[N], la, lb, lc, lp, lq, lr, i, j, neg;
signed main() {
    scanf("%s%s%s", a, b, c);
    la = strlen(a), lb = strlen(b), lc = strlen(c);
    for (i = 0; i < la; i++) {
        for (j = 0; j < lb; j++) {
            p[i + j] += (a[la - 1 - i] - '0') * (b[lb - 1 - j] - '0');
        }
    }
    lp = la + lb + 1;
    for (i = 0; i < lp; i++) {
        if (p[i] >= 10) {
            p[i + 1] += p[i] / 10, p[i] %= 10;
        }
    }
    while (lp > 1 && p[lp - 1] == 0) {
        lp--;
    }
    for (i = 0; i < lc; i++) {
        q[i] = c[lc - 1 - i] - '0';
    }
    lq = lc;
    while (lq > 1 && q[lq - 1] == 0) {
        lq--;
    }
    if (lp < lq) {
        neg = 1;
    } else if (lp == lq) {
        for (i = lp - 1; i >= 0; i--) {
            if (p[i] != q[i]) {
                neg = p[i] < q[i];
                break;
            }
        }
    }
    lr = max(lp, lq);
    for (i = 0; i < lr; i++) {
        int u = i < lp ? p[i] : 0, v = i < lq ? q[i] : 0;
        r[i] = neg ? v - u : u - v;
    }
    for (i = 1; i < lr; i++) {
        if (r[i - 1] < 0) {
            r[i - 1] += 10, r[i]--;
        }
    }
    while (lr > 1 && r[lr - 1] == 0) {
        lr--;
    }
    if (neg) {
        printf("-");
    }
    for (i = lr - 1; i >= 0; i--) {
        printf("%d", r[i]);
    }
    printf("\n");
    return 0;
}
