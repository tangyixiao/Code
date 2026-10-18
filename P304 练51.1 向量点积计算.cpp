#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N], b[N];
long long s;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        s += 1LL * a[i] * b[i];
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
