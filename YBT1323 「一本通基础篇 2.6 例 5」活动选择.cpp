#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, bg[N], ed[N], p[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> bg[i] >> ed[i];
        p[i] = i;
    }
}

inline void solve() {
    sort(p + 1, p + n + 1, [](int x, int y) { return ed[x] != ed[y] ? ed[x] < ed[y] : bg[x] < bg[y]; });
    int cnt = 0, last = -1;
    for (int i = 1; i <= n; i++) {
        if (bg[p[i]] >= last) {
            cnt++, last = ed[p[i]];
        }
    }
    cout << cnt << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
