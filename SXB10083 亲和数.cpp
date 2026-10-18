#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e5 + 5;

int a, b, len;
int pr[M], ct;
bool vis[M];
int rv[N];
long long sg[N], yv[N];

inline void sieve() {
    for (int i = 2; i < M; i++) {
        if (!vis[i]) {
            pr[ct++] = i;
            for (long long j = 1LL * i * i; j < M; j += i) {
                vis[j] = 1;
            }
        }
    }
}

inline void input() {
    cin >> a >> b;
    len = b - a + 1;
    for (int i = 0; i < len; i++) {
        rv[i] = a + i;
        sg[i] = 1;
    }
}

long long ds(long long y) {
    long long o = y, r = 1, t, f;
    for (int k = 0; k < ct; k++) {
        long long p = pr[k];
        if (p * p > y) {
            break;
        }
        if (y % p == 0) {
            t = 1;
            f = 1;
            while (y % p == 0) {
                y /= p;
                t *= p;
                f += t;
            }
            r *= f;
        }
    }
    if (y > 1) {
        r *= y + 1;
    }
    return r - o;
}

inline void solve() {
    sieve();
    for (int k = 0; k < ct; k++) {
        int p = pr[k];
        if (1ll * p * p > b) {
            break;
        }
        for (int j = (a + p - 1) / p * p; j <= b; j += p) {
            int i = j - a, e = 0;
            while (rv[i] % p == 0) {
                rv[i] /= p;
                e++;
            }
            long long t = 1, s = 1;
            for (int q = 0; q < e; q++) {
                t *= p;
                s += t;
            }
            sg[i] *= s;
        }
    }
    for (int i = 0; i < len; i++) {
        if (rv[i] > 1) {
            sg[i] *= rv[i] + 1;
        }
        yv[i] = sg[i] - (a + i);
    }
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (yv[i] > a + i && ds(yv[i]) == a + i) {
            ans++;
        }
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
