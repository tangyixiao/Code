#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = 2e7 + 5;
const int T = 1e4 + 5;

int t;
int l[T], r[T];
char p[M];
int c[M];

inline void sieve(int mx) {
    memset(p, 1, sizeof(char) * (mx + 1));
    p[0] = p[1] = 0;
    for (long long j = 4; j <= mx; j += 2) {
        p[j] = 0;
    }
    for (int i = 3; i <= mx; i += 2) {
        if (p[i]) {
            for (long long j = 1LL * i * i; j <= mx; j += 2 * i) {
                p[j] = 0;
            }
        }
    }
    c[1] = 0;
    for (int i = 2; i <= mx; i++) {
        c[i] = c[i - 1];
        if (!p[i]) {
            continue;
        }
        int s = 0;
        for (int x = i; x; x /= 10) {
            s += x % 10;
        }
        if (s >= 2 && s <= mx && p[s]) {
            c[i]++;
        }
    }
}

inline void input() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> l[i] >> r[i];
    }
}

inline void solve() {
    int mx = 0;
    for (int i = 1; i <= t; i++) {
        mx = max(mx, r[i]);
    }
    mx = min(mx, M - 1);
    sieve(mx);
    for (int i = 1; i <= t; i++) {
        cout << c[r[i]] - c[l[i] - 1] << "\n";
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
