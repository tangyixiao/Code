#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k, a[N];

inline void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    input();
    sort(a, a + n);
    cout << a[k - 1] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}