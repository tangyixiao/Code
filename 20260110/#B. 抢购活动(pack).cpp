#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5, M = 2e5 + 5, inf = 0x3f3f3f3f;
struct node {
    int w, c;
}a[N];
int n, m, dp[M];
signed main() {
    freopen("pack.in", "r", stdin);
    freopen("pack.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].c;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i].w; j--) {
            dp[j] = max(dp[j], dp[j - a[i].w] + a[i].c);
        }
    }
    cout << dp[m];
    return 0;
}