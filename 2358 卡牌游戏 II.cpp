#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
long long x;

inline void input() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        s += a[i];
        if (s >= x) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}