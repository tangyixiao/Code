#include <bits/stdc++.h>
using namespace std;

const int N = 40;
long long f[N];

inline void input() {
    f[1] = 1;
    for (int i = 2; i < N; i++) {
        f[i] = 2 * f[i - 1];
        for (int j = max(1, i - 5); j <= i - 2; j++) {
            f[i] += 4 * f[j];
        }
    }
    return;
}

inline void solve() {
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = max(1, n - 5); i <= n; i++) {
        ans += f[i];
    }
    cout << ans + f[n] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
