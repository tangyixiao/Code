#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 5;
int n;
long long a, b, c = 0, d = 1;

inline long long gcd(long long x, long long y) {
    while (y) {
        long long t = x % y;
        x = y, y = t;
    }
    return x;
}

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char p, q;
        cin >> a >> p >> b;
        c = c * b + d * a, d *= b;
        long long g = gcd(c, d);
        c /= g, d /= g;
    }
}

inline void solve() {
    if (d == 1) {
        cout << c << "\n";
    } else {
        cout << c << "/" << d << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
