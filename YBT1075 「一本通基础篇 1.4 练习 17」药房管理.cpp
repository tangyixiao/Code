#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int m, n, a[N];

inline void input() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    int s = m, r = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > s) {
            ++r;
        } else {
            s -= a[i];
        }
    }
    cout << r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}