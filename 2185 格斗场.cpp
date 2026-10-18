#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = 2e5 + 5;
int n, k, a[M], b[N], pre[N];

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[a[i]]++;
    }
}

inline void solve() {
    int m = 0;
    for (int i = 1; i <= n; ++i) {
        m = max(m, a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        pre[i] = pre[i - 1] + b[i];
    }
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        if (pre[min(m, a[i] + k)] - pre[a[i]] == 0) {
            ++s;
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}