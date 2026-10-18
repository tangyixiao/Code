#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int n;
long long a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    long long t;
    cin >> t;
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > t) {
            break;
        }
        t -= a[i], ++ans;
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
