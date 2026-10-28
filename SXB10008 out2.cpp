#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
int a[N], suf[N], st[N], res[N];
int n, top, rn;

signed main() {
    if (fopen("out.in", "r")) {
        freopen("out.in", "r", stdin);
        freopen("out.out", "w", stdout);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    suf[n + 1] = INF;
    for (int i = n; i >= 1; i--) {
        suf[i] = min(suf[i + 1], a[i]);
    }
    top = 0;
    rn = 0;
    for (int i = 1; i <= n; i++) {
        while (top > 0 && st[top] <= suf[i]) {
            res[++rn] = st[top--];
        }
        st[++top] = a[i];
    }
    while (top > 0) {
        res[++rn] = st[top--];
    }
    for (int i = 1; i <= rn; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}
