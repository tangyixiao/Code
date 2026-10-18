#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (; a[i] != i; ans++) {
            swap(a[i], a[a[i]]);
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
