#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

const int LEN = 505;

int q, res[LEN], bs[LEN], r[LEN], c[LEN];

inline void mul() {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < LEN; i++) {
        if (res[i]) {
            for (int j = 0; i + j < LEN; j++) {
                c[i + j] += res[i] * bs[j];
            }
        }
    }
    for (int i = 0; i < LEN - 1; i++) {
        r[i] = c[i] % 10, c[i + 1] += c[i] / 10;
    }
    r[LEN - 1] = c[LEN - 1] % 10;
    memcpy(res, r, sizeof(r));
}

inline void sq() {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < LEN; i++) {
        if (bs[i]) {
            for (int j = 0; i + j < LEN; j++) {
                c[i + j] += bs[i] * bs[j];
            }
        }
    }
    for (int i = 0; i < LEN - 1; i++) {
        r[i] = c[i] % 10, c[i + 1] += c[i] / 10;
    }
    r[LEN - 1] = c[LEN - 1] % 10;
    memcpy(bs, r, sizeof(r));
}

inline void input() {
    cin >> q;
}

inline void solve() {
    long long p = q;
    long long d = (long long)floor(p * log10(2.0)) + 1;
    res[0] = 1, bs[0] = 2;
    for (; p; p >>= 1) {
        if (p & 1) {
            mul();
        }
        sq();
    }
    for (int i = 0; i < LEN - 1; i++) {
        if (res[i]) {
            res[i]--;
            break;
        }
        res[i] = 9;
    }
    cout << d << "\n";
    for (int i = LEN - 6; i >= 0; i--) {
        cout << res[i];
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}