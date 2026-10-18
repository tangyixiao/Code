#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, phi[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    phi[1] = 1;
    for (int i = 2; i < n; i++) {
        phi[i] = i;
    }
    for (int i = 2; i < n; i++) {
        for (int j = i; j < n; j += i) {
            phi[j] = phi[j] / i * (i - 1);
        }
    }
    long long ans = 1;
    for (int i = 1; i < n; i++) {
        ans += 2LL * phi[i];
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
