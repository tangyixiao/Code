#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, a[N], cnt;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void pr(int v) {
    if (cnt++) {
        cout << " ";
    }
    cout << v;
}

inline void pre(int u) {
    if (u > n) {
        return;
    }
    pr(a[u]), pre(u << 1), pre(u << 1 | 1);
}

inline void mid(int u) {
    if (u > n) {
        return;
    }
    mid(u << 1), pr(a[u]), mid(u << 1 | 1);
}

inline void post(int u) {
    if (u > n) {
        return;
    }
    post(u << 1), post(u << 1 | 1), pr(a[u]);
}

inline void solve() {
    cnt = 0, pre(1);
    cout << "\n", cnt = 0, mid(1);
    cout << "\n", cnt = 0, post(1);
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
