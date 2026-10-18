#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N], tot;

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            a[++tot] = a[i];
        }
    }
    sort(a + 1, a + tot + 1, greater<int>());
    for (int i = 1; i <= tot; ++i) {
        cout << a[i] << (i == tot ? "\n" : " ");
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}