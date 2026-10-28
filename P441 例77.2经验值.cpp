#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, i, ans;
int p[N], d[N], pre[N], suf[N], pos[N];
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (i = 1; i <= n; i++) {
        pre[i] = i - 1, suf[i] = i + 1;
    }
    suf[n] = 0;
    for (i = 1; i <= n; i++) {
        int x = pos[d[i]];
        if (pre[x] > 0) {
            ans += p[pre[x]];
            suf[pre[x]] = suf[x];
        }
        if (suf[x] > 0) {
            ans += p[suf[x]];
            pre[suf[x]] = pre[x];
        }
    }
    cout << ans << "\n";
    return 0;
}
