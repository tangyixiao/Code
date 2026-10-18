#include <bits/stdc++.h>
using namespace std;

long long n;

inline void input() {
    cin >> n;
}

inline void solve() {
    long long r = 0;
    for (; n; n /= 10) {
        r = r * 10 + n % 10;
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
