#include <bits/stdc++.h>
using namespace std;

int a, b, m, n;

inline void input() {
    cin >> a >> b >> m >> n;
}

inline void solve() {
    int s = 0, x = a, y = b;
    for (int i = 1; i <= n; i++) {
        int c = x;
        s += c;
        if (c >= m) {
            break;
        }
        x = y, y = c + y;
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