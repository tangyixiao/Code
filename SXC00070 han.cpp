#include <bits/stdc++.h>
using namespace std;
const int N = 3.5e1 + 5;
int n, i;
long long p[N], pw[N], ans;
int w[N];
long long f(int k, int from, int to, int via) {
    if (k == 0) {
        return 0;
    }
    if (w[k] == via) {
        return -1;
    }
    long long r;
    if (w[k] == from) {
        r = f(k - 1, from, via, to);
        return r;
    }
    r = f(k - 1, via, to, from);
    if (r < 0) {
        return -1;
    }
    return r + pw[k - 1];
}
signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    pw[0] = 1;
    for (i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 2;
    }
    ans = f(n, 1, 2, 3);
    printf("%lld\n", ans);
    return 0;
}
