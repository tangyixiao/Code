#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
long long a[N], p, q;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 2; i <= n; i++) {
        long long d = a[i] - a[i - 1];
        if (d > 0) {
            p += d;
        } else {
            q -= d;
        }
    }
    cout << max(p, q) << "\n"
         << llabs(p - q) + 1 << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}