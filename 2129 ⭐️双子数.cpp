#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
long long a, b;
int c[N], cnt;
bool p[N];

inline void input() {
    cin >> a >> b;
}

inline void solve() {
    for (int i = 2; i < N; ++i) {
        if (p[i]) {
            continue;
        }
        c[++cnt] = i;
        if (1LL * i * i < N) {
            for (long long j = 1LL * i * i; j < N; j += i) {
                p[j] = true;
            }
        }
    }
    while (cnt > 1 && 1LL * c[cnt] * c[cnt] * c[cnt - 1] * c[cnt - 1] > b) {
        --cnt;
    }
    long long s = 0;
    for (int i = 1; i <= cnt; ++i) {
        for (int j = i + 1; j <= cnt; ++j) {
            long long x = 1LL * c[i] * c[i] * c[j] * c[j];
            if (x > b) {
                break;
            }
            if (x >= a) {
                ++s;
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