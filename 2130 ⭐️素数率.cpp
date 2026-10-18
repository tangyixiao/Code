#include <bits/stdc++.h>
using namespace std;

const int N = 46350, M = 1e6 + 5;
long long l, r;
int c[N];
bool p[N], s[M];

inline void input() {
    cin >> l >> r;
}

inline void solve() {
    for (int i = 2; i < N; ++i) {
        if (p[i]) {
            continue;
        }
        c[++c[0]] = i;
        if (1LL * i * i < N) {
            for (long long j = 1LL * i * i; j < N; j += i) {
                p[j] = true;
            }
        }
    }
    long long len = r - l + 1;
    for (long long i = 0; i < len; ++i) {
        s[i] = true;
    }
    if (l == 1) {
        s[0] = false;
    }
    for (int i = 1; i <= c[0]; ++i) {
        long long x = c[i];
        if (x * x > r) {
            break;
        }
        for (long long j = max(x * x, (l + x - 1) / x * x); j <= r; j += x) {
            s[j - l] = false;
        }
    }
    int cnt = 0;
    for (long long i = 0; i < len; ++i) {
        cnt += s[i];
    }
    cout << cnt << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
