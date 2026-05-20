#include <bits/stdc++.h>
using namespace std;
const int N = 8e2 + 5, M = 7e5 + 5, inf = 2e9;
int n, k, a[N][N], ta, w[M], ans = inf;
signed main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    cin >> n >> k;
    ta = k * k / 2 + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= n - k + 1; j++) {
            priority_queue<int> q;
            for (int l = 0; l <= k - 1; l++) {
                for (int r = 0; r <= k - 1; r++) {
                    q.push(a[i + l][j + r]);
                }
            }
            for (int i = 1; i < ta; i++) {
                q.pop();
            }
            ans = min(q.top(), ans);
        }
    }
    cout << ans << "\n";
    return 0;
}