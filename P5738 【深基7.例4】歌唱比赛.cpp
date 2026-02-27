#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5, inf = 1e9;
int n, m, a[N][N];
double avg(int id) {
    int minn = inf, maxx = -inf, sum = 0;
    for (int i = 1; i <= m; i++) {
        minn = min(minn, a[id][i]);
        maxx = max(maxx, a[id][i]);
        sum += a[id][i];
    }
    return (double)(sum - minn - maxx) / (m - 2);
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    double ans = -inf;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, avg(i));
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}