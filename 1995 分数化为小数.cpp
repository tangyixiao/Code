#include <bits/stdc++.h>
using namespace std;

long long n, m;

inline void input() {
    cin >> n >> m;
}

inline void solve() {
    printf("%lld.", n / m);
    long long r = n % m;
    for (int i = 1; i <= 100; i++) {
        r *= 10, printf("%lld", r / m), r %= m;
    }
    printf("\n");
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}