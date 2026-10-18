#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, a[N], b[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (b[j] < b[i]) {
                swap(a[i], a[j]), swap(b[i], b[j]);
            }
        }
    }
    int ans = 0, r = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > r) {
            r = b[i];
            ans++;
        }
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