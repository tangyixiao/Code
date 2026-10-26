#include <bits/stdc++.h>
using namespace std;

int n, i;
long long ans;

signed main() {
    scanf("%d", &n);
    ans = 0;
    for (i = 1; i <= n; i++) {
        ans += 1LL * i * (i + 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
