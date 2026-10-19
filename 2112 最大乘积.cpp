#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int M = 1e4 + 5;
int n, len, bl, d[M], b[M], a[N];

inline void input() {
    cin >> n;
}

inline void mul(int *p, int m) {
    int c = 0;
    for (int i = 0; i < len; i++) {
        int t = p[i] * m + c;
        p[i] = t % 10, c = t / 10;
    }
    for (; c > 0; c /= 10) {
        p[len++] = c % 10;
    }
}

inline int cmp(int *x, int *y) {
    if (len != bl) {
        return len < bl ? -1 : 1;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (x[i] != y[i]) {
            return x[i] < y[i] ? -1 : 1;
        }
    }
    return 0;
}

inline void solve() {
    len = bl = 1, d[0] = b[0] = 1;
    for (int k = 1; k * (k + 1) / 2 <= n; k++) {
        int s = n - k * (k + 1) / 2, t = s / k, r = s % k;
        len = 1, d[0] = 1;
        for (int i = 1; i <= k; i++) {
            a[i] = i + t + (i > k - r), mul(d, a[i]);
        }
        if (cmp(d, b) > 0) {
            bl = len;
            for (int i = 0; i < len; i++) {
                b[i] = d[i];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < bl; i++) {
        ans += b[i];
    }
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}