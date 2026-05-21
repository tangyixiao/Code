#include <bits/stdc++.h>
using namespace std;
const int MAXN = 805;
int n, k, m, A[MAXN][MAXN], B[MAXN][MAXN], s[MAXN][MAXN];
bool ok(int x) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            B[i][j] = (A[i][j] > x);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            s[i][j] = B[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    int t = k * k / 2;
    for (int i = k; i <= n; ++i)
        for (int j = k; j <= n; ++j) {
            int sum = s[i][j] - s[i - k][j] - s[i][j - k] + s[i - k][j - k];
            if (sum <= t)
                return true;
        }
    return false;
}
int main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
    int l = 0, r = 1e9, ans = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}