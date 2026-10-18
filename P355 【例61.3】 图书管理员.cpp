#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, a[N], b[N];

inline void input() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    int p = 10;
    while (p <= 1e7) {
        p *= 10;
    }
    for (int i = 1; i <= q; i++) {
        int len, v;
        cin >> len >> v;
        int k = 1;
        for (int j = 1; j < len; j++) {
            k *= 10;
        }
        int lo = lower_bound(a + 1, a + n + 1, v) - a;
        while (lo <= n && a[lo] % (k * 10) != v) {
            lo++;
        }
        cout << (lo <= n ? a[lo] : -1) << "\n";
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}