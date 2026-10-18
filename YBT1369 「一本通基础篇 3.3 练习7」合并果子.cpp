#include <bits/stdc++.h>
using namespace std;

const int N = 6e4 + 5;

int n, f[N], sz;

inline void up(int x) {
    while (x > 1 && f[x] < f[x >> 1]) {
        swap(f[x], f[x >> 1]), x >>= 1;
    }
}

inline void dn(int x) {
    for (; x * 2 <= sz;) {
        int y = x * 2;
        if (y + 1 <= sz && f[y + 1] < f[y]) {
            ++y;
        }
        if (f[x] <= f[y]) {
            break;
        }
        swap(f[x], f[y]), x = y;
    }
}

inline int pop() {
    int r = f[1];
    f[1] = f[sz--];
    dn(1);
    return r;
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> f[++sz];
        up(sz);
    }
}

inline void solve() {
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        int a = pop(), b = pop(), c = a + b;
        ans += c;
        f[++sz] = c;
        up(sz);
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
