#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
vector<int> primes;
int T, x, ans, v[N];
inline void Euler_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!v[i]) {
            primes.push_back(i);
        }
        for (int j : primes) {
            if ((long long)i * j > n) {
                break;
            }
            v[i * j] = j;
            if (!(i % j)) {
                break;
            }
        }
    }
    return;
}
inline void solve() {
    ans = 0;
    if (!v[x]) {
        ans = x;
        cout << ans << "\n";
        return;
    }
    for (;;) {
        if (!v[x]) {
            ans ^= x;
            break;
        }
        ans ^= v[x];
        x /= v[x];
    }
    cout << ans << "\n";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Euler_sieve(N);
    cin >> T;
    while (T--) {
        cin >> x;
        solve();
    }
    return 0;
}
