#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, l[N], r[N], id[N];

inline bool cmp(int x, int y) {
    return l[x] < l[y];
}

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        id[i] = i;
    }
}

inline void solve() {
    input();
    sort(id, id + n, cmp);
    int ans = 1, R = r[id[0]];
    for (int i = 1; i < n; i++) {
        int t = id[i];
        if (l[t] <= R) {
            R = max(R, r[t]);
        } else {
            ans++;
            R = r[t];
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}