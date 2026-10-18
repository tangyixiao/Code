#include <bits/stdc++.h>
using namespace std;

long long n;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            cout << n / i << "\n";
            return;
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
