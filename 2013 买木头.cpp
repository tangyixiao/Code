#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];
long long m, b[N], cnt;

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
}

inline bool ck(int x) {
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x) {
            cnt += a[i] / x * b[i];
        }
        if (cnt >= m) {
            return true;
        }
    }
    return false;
}

inline void solve() {
    int l = 1, r = 1e5, ans = 0;
    for (; l <= r;) {
        int mid = (l + r) / 2;
        if (ck(mid)) {
            ans = mid, l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
