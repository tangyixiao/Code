#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int a[N], m, n;

inline void input() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a, a + m);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        bool f = binary_search(a, a + m, k);
        cout << (f ? "YES" : "NO") << "\n";
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