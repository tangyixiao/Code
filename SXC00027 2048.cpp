#include <bits/stdc++.h>
using namespace std;

const int N = 262150, M = 65;
int n, a[N];
static int pre[N], cur[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int v = 1; v < M; v++) {
        for (int i = 1; i <= n; i++) {
            int e = 0;
            if (a[i] == v) {
                e = i + 1;
            } else if (pre[i] != 0 && pre[pre[i]] != 0) {
                e = pre[pre[i]];
            }
            cur[i] = e;
            if (e != 0) {
                ans = v;
            }
        }
        for (int i = 0; i <= n + 1; i++) {
            pre[i] = cur[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
