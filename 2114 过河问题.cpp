#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[i]) {
                swap(a[j], a[i]);
            }
        }
    }
}

inline void solve() {
    long long ans = 0;
    int k = n;
    for (; k > 3; k -= 2) {
        ans += min(1LL * a[1] + 2 * a[2] + a[k], 2LL * a[1] + a[k - 1] + a[k]);
    }
    if (k == 3) {
        ans += 1LL * a[1] + a[2] + a[3];
    } else if (k == 2) {
        ans += a[2];
    } else if (k == 1) {
        ans += a[1];
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
