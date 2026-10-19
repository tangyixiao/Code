#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, n, ans = 1;

inline void input() {
    cin >> a >> n;
    return;
}

inline void solve() {
    input();
    for (int i = 1; i <= n; i++) {
        ans *= a;
    }
    cout << ans << "\n";
    return;
}

signed main() {
    solve();
    return 0;
}