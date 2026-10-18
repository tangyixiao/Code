#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, l[N], r[N], t[N], s, e;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        if (i == 0 || l[i] < s) {
            s = l[i];
        }
        if (i == 0 || r[i] > e) {
            e = r[i];
        }
    }
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        t[l[i]]++;
        t[r[i]]--;
    }
    int cur = 0, on = 0, off = 0, mx = 0, my = 0;
    for (int i = s; i < e; i++) {
        cur += t[i];
        if (cur > 0) {
            mx = max(mx, ++on);
            off = 0;
        } else {
            my = max(my, ++off);
            on = 0;
        }
    }
    cout << mx << " " << my << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
