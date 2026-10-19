#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, c[N], mx;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a, c[a]++, mx = max(mx, a);
    }
    for (int i = 0; i <= mx; i++) {
        cout << c[i] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}