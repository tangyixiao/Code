#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, a[N], b[N];

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (m > 0 && a[i] == b[m]) {
            continue;
        }
        b[++m] = a[i];
    }
    cout << b[k] << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}