#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
long long a, b, ba = 1, bb = 1, ans = 1;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (b * ba > bb * a) {
            ba = a, bb = b, ans = i;
        }
    }
}

inline void solve() {
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
