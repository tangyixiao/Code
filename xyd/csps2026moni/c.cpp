#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, a[N], b[N], t;
long long fen[N], cnt, ev;
unsigned long long w0[(N >> 6) + 2], w1[(N >> 12) + 2], w2;
inline void upd(int v, bool f) {
    unsigned long long m = 1ULL << (v & 63);
    if (f) {
        w0[v >> 6] |= m, w1[v >> 12] |= 1ULL << ((v >> 6) & 63), w2 |= 1ULL << (v >> 12);
        return;
    }
    w0[v >> 6] &= ~m;
    if (!w0[v >> 6]) {
        w1[v >> 12] &= ~(1ULL << ((v >> 6) & 63));
        if (!w1[v >> 12]) {
            w2 &= ~(1ULL << (v >> 12));
        }
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("sort.in", "r", stdin), freopen("sort.out", "w", stdout);
    cin >> n >> k, t = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i <= k && a[i] != i) {
            t = 0;
        }
    }
    if (t || k == 2) {
        for (int i = 1; i <= n; i++) {
            for (ev = 0, t = a[i]; t > 0; t -= t & -t) {
                ev += fen[t];
            }
            cnt += (i - 1 - ev + k - 2) / (k - 1);
            for (t = a[i]; t <= n; t += t & -t) {
                fen[t]++;
            }
        }
        cout << cnt << "\n";
        return 0;
    }
    for (;;) {
        if (is_sorted(a + 1, a + n + 1)) {
            break;
        }
        ev = 0;
        if (!is_sorted(a + 1, a + k + 1)) {
            ev++, sort(a + 1, a + k + 1);
        }
        memset(w0, 0, sizeof w0), memset(w1, 0, sizeof w1), w2 = 0, b[1] = a[1];
        for (int i = 2; i <= k; i++) {
            upd(a[i], true);
        }
        for (int j = k + 1; j <= n; j++) {
            t = 63 - __builtin_clzll(w2), t = (t << 6) + 63 - __builtin_clzll(w1[t]);
            if (a[j] < (t = (t << 6) + 63 - __builtin_clzll(w0[t]))) {
                ev++;
            }
            upd(a[j], true);
            t = __builtin_ctzll(w2), t = (t << 6) + __builtin_ctzll(w1[t]);
            b[j - k + 1] = (t << 6) + __builtin_ctzll(w0[t]), upd(b[j - k + 1], false);
        }
        t = n - k + 2;
        for (int w = 0; w <= (n >> 6); w++) {
            for (unsigned long long s = w0[w]; s; s &= s - 1) {
                b[t++] = (w << 6) + __builtin_ctzll(s);
            }
        }
        for (int i = 1; i <= n; i++) {
            a[i] = b[i];
        }
        cnt += ev;
        if (!ev) {
            break;
        }
    }
    cout << cnt << "\n";
    return 0;
}
