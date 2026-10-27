#include <bits/stdc++.h>
using namespace std;

int n, k, i, r, c, cnt, ans;
int rw[105], cl[105], d1[205], d2[205], own[105][105];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (i = 1; i <= k; i++) {
        cin >> r >> c;
        rw[r]++, cl[c]++;
        d1[r - c + 100]++, d2[r + c]++;
        own[r][c] = 1;
    }
    ans = 0;
    for (r = 1; r <= n; r++) {
        for (c = 1; c <= n; c++) {
            cnt = rw[r] + cl[c] + d1[r - c + 100] + d2[r + c] - 3 * own[r][c];
            if (cnt == k) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
