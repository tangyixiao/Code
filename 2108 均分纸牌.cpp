#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        s += a[i];
    }
    int avg = s / n, cnt = 0, pre = 0;
    for (int i = 1; i < n; ++i) {
        pre += a[i] - avg;
        if (pre != 0) {
            ++cnt;
        }
    }
    cout << cnt << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
