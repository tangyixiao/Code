#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans;
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = n + 1; i < m; i++) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            ans += i;
        }
    }
    printf("%lld", ans);
    return 0;
}