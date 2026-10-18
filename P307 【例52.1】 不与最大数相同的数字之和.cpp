#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a[N], mx;
long long s;

inline void input() {
    cin >> n;
    mx = -1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], mx = max(mx, a[i]);
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        if (a[i] != mx) {
            s += a[i];
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
