#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N], p;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    input();
    p = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= a[p]) {
            p = i;
        }
    }
    cout << p + 1 << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}