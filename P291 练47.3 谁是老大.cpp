#include <bits/stdc++.h>
using namespace std;

const int N = 5 + 5;

int a[N], n;

inline void input() {
    for (int i = 1; i <= 5; i++) {
        cin >> a[i];
    }
}

inline int mx(int x) {
    return x >= 5 ? a[5] : max(a[x], mx(x + 1));
}

inline void solve() {
    cout << mx(1) << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
