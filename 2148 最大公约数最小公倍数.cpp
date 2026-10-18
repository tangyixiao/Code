#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 15;
long long n, m;

inline long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b, b = t;
    }
    return a;
}

inline void input() {
    cin >> n >> m;
}

inline void solve() {
    long long g = gcd(n, m);
    cout << g << " " << n / g * m << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
