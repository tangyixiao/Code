#include <bits/stdc++.h>
using namespace std;

const int N = 3e1 + 5;

int n, a[N], b[N], c[N], d[N], tot;

inline void input() {
    cin >> n;
}

inline void dfs(int x) {
    if (x > n) {
        tot++;
        if (tot <= 3) {
            for (int i = 1; i <= n; i++) {
                cout << a[i] << (i == n ? "\n" : " ");
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] || c[x + i] || d[x - i + n]) {
            continue;
        }
        a[x] = i, b[i] = 1, c[x + i] = 1, d[x - i + n] = 1;
        dfs(x + 1);
        b[i] = c[x + i] = d[x - i + n] = 0;
    }
}

inline void solve() {
    dfs(1);
    cout << tot << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
