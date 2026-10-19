#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], r;
char s[N][15];

inline void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> s[i];
    }
    for (int i = 0; i < m; i++) {
        int t, d;
        cin >> t >> d;
        d %= n;
        r = (r + (a[r] == t ? -d : d) + n) % n;
    }
}

inline void solve() {
    cout << s[r] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
