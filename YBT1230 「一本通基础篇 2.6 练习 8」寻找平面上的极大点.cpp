#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int a[N][2], b[N][2], n, m;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }
    return;
}

inline void solve() {
    for (int i = 0; i < n; ++i) {
        bool ok = 1;
        for (int j = 0; j < n; ++j) {
            if (a[j][0] >= a[i][0] && a[j][1] >= a[i][1] &&
                (a[j][0] != a[i][0] || a[j][1] != a[i][1])) {
                ok = 0;
            }
        }
        if (!ok) {
            continue;
        }
        b[m][0] = a[i][0], b[m][1] = a[i][1], ++m;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (b[j][0] < b[i][0]) {
                swap(b[i][0], b[j][0]), swap(b[i][1], b[j][1]);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (i) {
            cout << ",";
        }
        cout << "(" << b[i][0] << "," << b[i][1] << ")";
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
