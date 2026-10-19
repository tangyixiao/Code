#include <bits/stdc++.h>
using namespace std;

int x, l = 1, r = 100;

inline void input() {
    cin >> x;
}

inline void solve() {
    while (l <= r) {
        int m = (l + r) / 2;
        cout << m << "\n";
        if (m == x) {
            cout << "成功！\n";
            return;
        }
        if (m < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << "失败！\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}