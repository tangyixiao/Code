#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int l, r;

bool chk(int x) {
    int c[N] = {};
    for (int t = x; t; t /= 10) {
        c[t % 10]++;
    }
    for (int t = x; t; t /= 10) {
        int d = t % 10;
        if (c[d] != d) {
            return false;
        }
    }
    return true;
}

inline void input() {
    cin >> l >> r;
}

inline void solve() {
    int s = 0;
    for (int i = l; i <= r; i++) {
        if (chk(i)) {
            s += i;
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
