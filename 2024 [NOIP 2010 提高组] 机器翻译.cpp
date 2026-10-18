#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int cap, n, q[N], c[N], len, ans;

inline void input() {
    cin >> cap >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (c[x]) {
            continue;
        }
        ans++;
        if (len == cap) {
            c[q[0]] = 0;
            for (int j = 0; j < len - 1; j++) {
                q[j] = q[j + 1];
            }
            len--;
        }
        q[len] = x, c[x] = 1, len++;
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