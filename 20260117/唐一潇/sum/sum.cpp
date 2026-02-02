#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct node {
    int l, r;
} op[N], idx[N];
int n, q, b[N], a[N], pr[N], sum[N], ans;
bool cmp(node A, node B) {
    return A.l < B.l;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> op[i].l >> op[i].r;
        pr[op[i].l]++;
        pr[op[i].r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        idx[i].l = idx[i - 1].l + pr[i];
        idx[i].r = i;
    }
    sort(idx + 1, idx + 1 + n, cmp);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        b[idx[i].r] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + b[i];
    }
    for (int i = 1; i <= q; i++) {
        ans += (sum[op[i].r] - sum[op[i].l - 1]);
    }
    cout << ans;
    return 0;
}