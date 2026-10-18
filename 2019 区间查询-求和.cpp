#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m;
long long s[N];

inline void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x, s[i] = s[i - 1] + x;
    }
}

inline void solve() {
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        cout << s[y] - s[x - 1] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
