#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N], t[N], top;

inline void input() {
    int x;
    while (cin >> x) {
        a[++n] = x;
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(t + 1, t + top + 1, a[i]) - t;
        t[k] = a[i];
        if (k > top) {
            top = k;
        }
    }
    cout << top << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
