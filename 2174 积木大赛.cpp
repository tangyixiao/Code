#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    input();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int t = i ? a[i] - a[i - 1] : a[i];
        if (t > 0) {
            ans += t;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}