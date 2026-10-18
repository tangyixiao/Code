#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, c[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    sort(c + 1, c + n + 1);
}

inline void solve() {
    int a;
    for (int i = 1; i <= m; i++) {
        cin >> a;
        cout << upper_bound(c + 1, c + n + 1, a) - c - 1 << "\n";
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}