#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, V = 2e4 + 5, mod = 998244353;
int n, a[N], f[N][V << 1], ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j < i; j++) {
            (f[i][a[i] - a[j] + V] += f[j][a[i] - a[j] + V] + 1) %= mod;
            (ans += f[j][a[i] - a[j] + V] + 1) %= mod;
        }
    }
    cout << (ans + n) % mod;
    return 0;
}