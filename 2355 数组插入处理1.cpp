#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a, b, p[N], m;

inline void input() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
}

inline void solve() {
    input();
    m = 0;
    for (int i = 0; i < n; i++) {
        p[m++] = p[i];
    }
    for (int i = m; i > 0; i--) {
        p[i] = p[i - 1];
    }
    p[0] = a, p[m + 1] = b, m += 2;
    for (int i = 0; i < m; i++) {
        if (i) {
            cout << " ";
        }
        cout << p[i];
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}