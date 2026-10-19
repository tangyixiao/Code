#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;

int n, a[N], m;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            a[++m] = a[i];
        }
    }
}

inline void solve() {
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++) {
        cout << a[i] << (i == m ? "\n" : ",");
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
