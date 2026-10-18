#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
int f[N];
long long ans;

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        if (f[i] == i) {
            for (int j = i; j <= n; j += i) {
                f[j] = f[j] / i * (i - 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans += f[i];
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}