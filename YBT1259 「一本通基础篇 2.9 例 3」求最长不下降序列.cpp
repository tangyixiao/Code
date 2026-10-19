#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, b[N], f[N], pre[N], s[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (b[j] <= b[i] && f[j] + 1 > f[i]) {
                f[i] = f[j] + 1, pre[i] = j;
            }
        }
    }
    int mx = 0, pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (f[i] > mx) {
            mx = f[i], pos = i;
        }
    }
    int cnt = 0;
    for (int i = pos; i; i = pre[i]) {
        s[cnt++] = b[i];
    }
    cout << "max=" << mx << "\n";
    for (int i = cnt - 1; i >= 0; --i) {
        cout << s[i] << (i ? " " : "\n");
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
