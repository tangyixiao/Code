#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, i, x, c[N], s[N], a[N], t;
int lowbit(int k) {
    return k & -k;
}
void add(int k, int v) {
    for (; k <= n; k += lowbit(k)) {
        c[k] += v;
    }
}
int sum(int k) {
    int r = 0;
    for (; k > 0; k -= lowbit(k)) {
        r += c[k];
    }
    return r;
}
int kth(int k) {
    int pos = 0;
    for (int pw = 1 << 18; pw; pw >>= 1) {
        if (pos + pw <= n && c[pos + pw] < k) {
            pos += pw, k -= c[pos];
        }
    }
    return pos + 1;
}
signed main() {
    if (fopen("moo.in", "r")) {
        freopen("moo.in", "r", stdin);
        freopen("moo.out", "w", stdout);
    }
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        s[i] = i - 1;
        add(i, 1);
    }
    for (i = 2; i <= n; i++) {
        scanf("%d", &x);
        s[i] = x;
    }
    for (i = n; i >= 1; i--) {
        t = kth(s[i] + 1);
        a[i] = t;
        add(t, -1);
    }
    for (i = 1; i <= n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
