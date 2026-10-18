#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, a[N], t[N];
long long ans;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void cd(int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    cd(l, m);
    cd(m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        } else {
            t[k++] = a[j++];
            ans += m - i + 1;
        }
    }
    while (i <= m) {
        t[k++] = a[i++];
    }
    while (j <= r) {
        t[k++] = a[j++];
    }
    for (int x = l; x <= r; x++) {
        a[x] = t[x];
    }
    return;
}

inline void solve() {
    ans = 0;
    cd(1, n);
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
