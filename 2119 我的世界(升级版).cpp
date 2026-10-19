#include <bits/stdc++.h>
using namespace std;

long long n, s;

inline void input() {
    cin >> n;
}

inline void solve() {
    s = 6 * n + 2;
    for (long long a = 1; a * a * a <= n; ++a) {
        if (n % a) {
            continue;
        }
        for (long long b = a; b * b <= n / a; ++b) {
            if (n / a % b) {
                continue;
            }
            long long c = n / a / b;
            if (2 * (a * b + b * c + c * a) < s) {
                s = 2 * (a * b + b * c + c * a);
            }
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
