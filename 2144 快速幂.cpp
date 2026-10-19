#include <bits/stdc++.h>
using namespace std;

unsigned long long a, b;
long long p;

inline void input() {
    cin >> a >> b >> p;
}

inline void solve() {
    unsigned long long r = 1 % p, x = a % p;
    while (b) {
        if (b & 1) {
            r = r * x % p;
        }
        x = x * x % p, b >>= 1;
    }
    cout << r << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
