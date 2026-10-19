#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t, n;
int a[N], b[N], p[N], q[N];
long long suf[N];
long long ans;

inline bool cmp(int x, int y) {
    if (a[x] != a[y]) {
        return a[x] < a[y];
    }
    return x < y;
}

inline void input() {
    cin >> t;
}

inline void solve() {
    for (; t--;) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = i;
        }
        sort(b + 1, b + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            p[b[i]] = i > 1 && a[b[i]] == a[b[i - 1]] ? b[i - 1] : 0;
            q[b[i]] = i < n && a[b[i]] == a[b[i + 1]] ? b[i + 1] : 0;
        }
        suf[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            suf[i] = suf[i + 1] + (q[i] == 0);
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i] == 0) {
                ans += suf[i];
            }
        }
        cout << ans << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
