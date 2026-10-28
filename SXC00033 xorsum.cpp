#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const long long M = 998244353;

int n, i, b;
long long a[N], p[N], ans;
long long cnt[2], sum[2];

signed main() {
    scanf("%d", &n);
    p[0] = 0;
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        p[i] = p[i - 1] ^ a[i];
    }
    ans = 0;
    for (b = 0; b < 31; b++) {
        cnt[0] = cnt[1] = 0;
        sum[0] = sum[1] = 0;
        long long c = 0;
        for (i = 0; i <= n; i++) {
            int nb = (p[i] >> b) & 1;
            int ob = 1 - nb;
            c = (c + cnt[ob] * i - sum[ob]) % M;
            cnt[nb]++;
            sum[nb] += i;
        }
        c = (c % M + M) % M;
        ans = (ans + c * ((1LL << b) % M)) % M;
    }
    printf("%lld\n", ans);
    return 0;
}
