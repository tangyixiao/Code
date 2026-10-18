#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    input();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 9 == 0 && a[i] % 8 != 0) {
            ans++;
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