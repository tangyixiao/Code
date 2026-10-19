#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
typedef unsigned long long ull;
int T, n, p[N];

inline void input() {
    cin >> T;
}

inline void solve() {
    while (T--) {
        ull a, b;
        cin >> a >> b >> n;
        int f = 0, g = 1 % n, c = 0;
        for (c = 1;; c++) {
            int t = (f + g) % n;
            f = g, g = t;
            if (f == 0 && g == 1 % n) {
                break;
            }
        }
        ull e = 1, x = a % c;
        for (int i = 0; i < 64; i++) {
            if ((b >> i) & 1) {
                e = e * x % c;
            }
            x = x * x % c;
        }
        p[0] = 0, p[1] = 1 % n;
        for (int i = 2; i <= e; i++) {
            p[i] = (p[i - 1] + p[i - 2]) % n;
        }
        cout << p[e] << "\n";
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
