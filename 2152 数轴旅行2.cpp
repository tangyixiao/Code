#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];
long long d;

inline void input() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    long long g = a[1];
    for (int i = 2; i <= n; ++i) {
        g = __gcd(g, (long long)a[i]);
    }
    cout << (d % g == 0 ? "Yes\n" : "No\n");
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
