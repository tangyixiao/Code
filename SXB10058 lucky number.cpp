#include <bits/stdc++.h>
using namespace std;
long long n, ans;
void dfs(long long x, int d) {
    if (x > n) {
        return;
    }
    if (x) {
        ans++;
    }
    if (d == 12) {
        return;
    }
    dfs(x * 10 + 4, d + 1);
    dfs(x * 10 + 7, d + 1);
}
signed main() {
    scanf("%lld", &n);
    ans = 0;
    dfs(0, 0);
    printf("%lld\n", ans);
    return 0;
}
