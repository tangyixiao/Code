#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N], id[N], vis[N], ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[id[j]] < a[id[i]]) {
                swap(id[i], id[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        a[id[i]] = i;
    }
}

inline void solve() {
    ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        int k = 0, x = i;
        for (; !vis[x]; x = a[x]) {
            vis[x] = 1, k++;
        }
        ans += k - 1;
    }
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