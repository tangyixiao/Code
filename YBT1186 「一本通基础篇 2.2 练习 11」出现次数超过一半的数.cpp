#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e2 + 5;

int a[N], c[M], n, mx, f;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, abs(a[i]));
    }
}

inline void solve() {
    for (int i = 0; i < n; ++i) {
        ++c[a[i] + mx];
        if (c[a[i] + mx] > n / 2) {
            cout << a[i] << "\n";
            f = 1;
            break;
        }
    }
    if (!f) {
        cout << "no" << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
