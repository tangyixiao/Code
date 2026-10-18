#include <bits/stdc++.h>
using namespace std;

long long n, i, j;

inline void input() {
    cin >> n >> i >> j;
}

inline void solve() {
    long long a = min(i, n - i + 1), b = min(j, n - j + 1);
    long long k = min(a, b), len = n - 2 * k + 2;
    long long r = i - k + 1, c = j - k + 1;
    long long s = 4 * (k - 1) * (n - k + 1) + 1;
    long long ans;
    if (r == 1) {
        ans = s + c - 1;
    } else if (c == len) {
        ans = s + len - 1 + r - 1;
    } else if (r == len) {
        ans = s + 2 * (len - 1) + len - c;
    } else {
        ans = s + 3 * (len - 1) + len - r;
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
