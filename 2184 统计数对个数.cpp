#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
const int M = 1e5 + 5;
int n, x, a[M], b[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    cin >> x;
}

inline void solve() {
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        int v = x - a[i];
        if (v > 0 && v != a[i] && b[v]) {
            ++c;
        }
    }
    cout << c / 2 << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}