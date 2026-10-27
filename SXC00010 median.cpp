#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n, k, i, p, ans, s;
int a[N], b[N];
long long c[2][2 * N];
signed main() {
    scanf("%lld%lld", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == k) {
            p = i;
        }
    }
    for (i = 1; i <= n; i++) {
        if (a[i] > k) {
            b[i] = 1;
        } else if (a[i] < k) {
            b[i] = -1;
        } else {
            b[i] = 0;
        }
    }
    s = 0;
    c[0][N] = 1;
    for (i = 1; i < p; i++) {
        s += b[i];
        c[i % 2][s + N]++;
    }
    ans = 0;
    for (i = p; i <= n; i++) {
        s += b[i];
        ans += c[(i % 2) ^ 1][s + N];
    }
    printf("%lld\n", ans);
    return 0;
}
