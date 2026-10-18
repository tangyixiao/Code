#include <bits/stdc++.h>
using namespace std;

const int N = 2e1 + 5;

int a[N], h, ans;

inline void input() {
    for (int i = 1; i <= 10; i++) {
        cin >> a[i];
    }
    cin >> h;
}

inline void solve() {
    for (int i = 1; i <= 10; i++) {
        if (a[i] <= h + 30) {
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
