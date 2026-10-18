#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, a[N], b[N], c[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && a[i] == a[i - 1]) {
            continue;
        }
        b[++m] = a[i];
    }
    cout << m << "\n";
    for (int i = 1; i <= m; i++) {
        cout << b[i] << (i == m ? "\n" : " ");
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}