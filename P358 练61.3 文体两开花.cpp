#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], b[N], c[N], k;

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
}

inline void solve() {
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++) {
        if (binary_search(b + 1, b + m + 1, a[i])) {
            c[++k] = a[i];
        }
    }
    sort(c + 1, c + k + 1);
    for (int i = 1; i <= k; i++) {
        cout << c[i] << " ";
    }
    cout << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}