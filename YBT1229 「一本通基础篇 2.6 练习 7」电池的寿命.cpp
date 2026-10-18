#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, a[N];

void solve();

inline void input() {
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return;
}

inline void solve() {
    int s = 0, m = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i], m = max(m, a[i]);
    }
    printf("%.1f\n", min(s / 2.0, s - m * 1.0));
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    return 0;
}
