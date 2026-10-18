#include <bits/stdc++.h>
using namespace std;

long long n;

inline void input() { cin >> n; }

inline void solve() {
    for (long long t = 1; t < 1e6; ++t) {
        long long s = t * (t + 1) / 2 - n;
        if (s > 0 && s % 3 == 0 && s / 3 <= t) {
            cout << s / 3 << " " << t << "\n";
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