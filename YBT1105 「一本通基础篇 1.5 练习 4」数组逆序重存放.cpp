#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        cout << a[n - i + 1] << (i == n ? "\n" : " ");
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}