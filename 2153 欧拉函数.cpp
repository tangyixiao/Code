#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 5;

long long n, phi;

inline void input() {
    cin >> n;
}

inline void solve() {
    phi = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            phi = phi / i * (i - 1);
            for (; n % i == 0; n /= i) {
            }
        }
    }
    if (n > 1) {
        phi = phi / n * (n - 1);
    }
    cout << phi << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}