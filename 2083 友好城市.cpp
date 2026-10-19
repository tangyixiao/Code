#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

struct P {
    int x, y;
} a[N];

int n, f[N];

inline bool ck(P i, P j) {
    return i.x < j.x;
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + n + 1, ck);
}

inline void solve() {
    int len = 0;
    for (int i = 1; i <= n; ++i) {
        int k = 0;
        for (; k < len && f[k] < a[i].y; ++k) {
        }
        if (k == len) {
            ++len;
        }
        f[k] = a[i].y;
    }
    cout << len << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
