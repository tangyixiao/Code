#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int k, s, n, w[N];
double v[N], ans;

struct node {
    int w;
    double v;
} a[N];

signed main() {
    cin >> k;
    while (k--) {
        cin >> s >> n, ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].w >> a[i].v, a[i].v /= a[i].w;
        }
        sort(a + 1, a + n + 1, [](node x, node y) { return x.v > y.v; });
        for (int i = 1; i <= n && s > 0; i++) {
            double t = min((double)s, (double)a[i].w);
            ans += t * a[i].v, s -= (int)t;
        }
        cout << fixed << setprecision(2) << ans << "\n";
    }
    return 0;
}
