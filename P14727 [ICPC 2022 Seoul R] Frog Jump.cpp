#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, inf = 1e18;
struct node {
    int l, r, id;
    bool operator<(const node& A) const {
        return l < A.l;
    }
} a[N];

int n, k, ans, cnt, now, maxr = -inf, st[N], l[N], r[N], dis[N], sum[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("frjp.in", "r", stdin);
    //freopen("frjp.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i].l > maxr) {
            l[++cnt] = a[i].l;
            r[cnt] = a[i].r;
            maxr = a[i].r;
        } else {
            r[cnt] = max(r[cnt], (int)a[i].r);
            maxr = max(maxr, (int)a[i].r);
        }
        st[a[i].id] = cnt;
    }

    for (int i = 1; i < cnt; i++) {
        dis[i] = l[i + 1] - r[i];
        sum[i + 1] = sum[i] + dis[i];
    }
    now = st[1];
    for (int s; k--;) {
        cin >> s;
        if (st[s] != now) {
            ans += abs(sum[st[s]] - sum[now]);
            now = st[s];
        }
    }
    cout << ans;
    return 0;
}