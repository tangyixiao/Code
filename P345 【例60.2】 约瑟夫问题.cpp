#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, a[N];

inline void input() { cin >> n >> m; }

inline void solve() {
    int sz = n, p = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (p > sz) {
            p = 1;
        }
        for (int j = 1; j < m; j++) {
            p = p < sz ? p + 1 : 1;
        }
        cout << a[p] << (i == n ? "\n" : " ");
        for (int j = p; j < sz; j++) {
            a[j] = a[j + 1];
        }
        sz--;
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}