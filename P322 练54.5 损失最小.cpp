#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m;
int a[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) {
        cout << a[i] << "\n";
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
