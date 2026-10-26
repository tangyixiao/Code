#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
using ll = long long;
const int N = 2e5 + 5;
const ll inf = 4e18;
int n;
ll t[N], d[N], s[N], pre[N], suf[N], ans;

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> t[i] >> d[i], s[i] = s[i - 1] + t[i]; }
    pre[0] = suf[n + 1] = -inf;
    for (int i = 1; i <= n; i++) { pre[i] = max(pre[i - 1], s[i] - d[i]); }
    for (int i = n; i >= 1; i--) { suf[i] = max(suf[i + 1], s[i] - d[i]); }
    ans = max(0LL, pre[n]);
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max({0LL, t[i] - d[i], pre[i - 1] + t[i], suf[i + 1]}));
        ans = min(ans, max({0LL, pre[i - 1], suf[i + 1] - t[i], s[n] - d[i]}));
    }
    cout << ans << "\n";
    return;
}
} // namespace TANGYIXIAO

signed main() {
    freopen("ends.in", "r", stdin), freopen("ends.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    TANGYIXIAO::solve();
    return 0;
}
