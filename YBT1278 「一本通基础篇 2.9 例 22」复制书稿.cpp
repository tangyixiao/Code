#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int m, k, a[N];

inline void input() {
    cin >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    return;
}

inline bool chk(int t) {
    int c = 1, s = 0;
    for (int i = 1; i <= m; i++) {
        if (s + a[i] > t) {
            c++;
            s = a[i];
        } else {
            s += a[i];
        }
    }
    return c <= k;
}

inline void solve() {
    if (k == 0) {
        return;
    }
    int l = 0, h = 0;
    for (int i = 1; i <= m; i++) {
        h += a[i];
    }
    while (l < h) {
        int mid = (l + h) / 2;
        if (chk(mid)) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    int p = 0, s = 0;
    for (int i = 1; i < k; i++) {
        int st = p + 1;
        while (p < m - (k - i) && s + a[p + 1] <= l) {
            p++;
            s += a[p];
        }
        cout << st << " " << p << "\n";
        s = 0;
    }
    cout << p + 1 << " " << m << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}