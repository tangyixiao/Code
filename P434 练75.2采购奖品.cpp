#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
struct node {
    int p, c;
} a[N];
int n;
long long m;
int ans;

signed main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].p >> a[i].c;
    }
    sort(a + 1, a + n + 1, [](node x, node y) { return x.p < y.p; });
    for (int i = 1; i <= n; i++) {
        long long k = min(1LL * a[i].c, m / a[i].p);
        ans += (int)k, m -= k * a[i].p;
    }
    cout << ans << "\n";
    return 0;
}
