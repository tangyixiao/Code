#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, cur, tot;
bool ok;
string h[N], o;

inline void input() {
    cin >> n;
    cur = tot = -1;
    for (int i = 1; i <= n; i++) {
        cin >> o;
        ok = true;
        if (o == "v") {
            cin >> o;
            h[++tot] = o, cur = tot;
        } else if (o == "b") {
            ok = cur > 0, cur -= ok;
        } else {
            ok = cur < tot, cur += ok;
        }
        cout << (ok && cur >= 0 ? h[cur] : "?") << "\n";
    }
}

inline void solve() {
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}