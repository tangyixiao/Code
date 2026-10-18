#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, ans;

bool chk(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return x > 1;
}

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 11; i <= n; i++) {
        int t = i, r = 0;
        for (; t; t /= 10) {
            r = r * 10 + t % 10;
        }
        if (chk(i) && r == i) {
            ans++;
        }
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
