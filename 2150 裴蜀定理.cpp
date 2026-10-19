#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long a[N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
}

inline void solve() {
    long long g = 0;
    for (int i = 0; i < n; i++) {
        g = __gcd(g, a[i]);
    }
    cout << g << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
