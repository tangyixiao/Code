#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, x, a[N], f[N];

inline void input() {
    cin >> n >> x;
    for (int i = n; i >= 1; --i) {
        a[i] = x % 10;
        x /= 10;
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * i;
    }
}

inline void solve() {
    int r = 1;
    for (int i = 1; i <= n; ++i) {
        int c = 0;
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] < a[i]) {
                ++c;
            }
        }
        r += c * f[n - i];
    }
    cout << r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}