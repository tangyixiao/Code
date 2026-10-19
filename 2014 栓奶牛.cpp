#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
long long p[N];

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> p[i];
    }
    sort(p + 1, p + k + 1);
}

inline bool ck(long long x) {
    int c = 1;
    long long q = p[1];
    for (int i = 2; i <= k; ++i) {
        if (p[i] - q >= x) {
            ++c, q = p[i];
        }
    }
    return c >= n;
}

inline void solve() {
    long long l = 0, r = p[k] - p[1] + 1, ans = 0;
    for (; l < r;) {
        long long mid = (l + r + 1) / 2;
        if (ck(mid)) {
            ans = mid, l = mid;
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
