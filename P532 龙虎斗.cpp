#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long c[N], dl, dr;
int n, m, p1, p2;
long long s1, s2;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    cin >> m >> p1 >> s1 >> s2;
}

inline void solve() {
    for (int i = 1; i < m; ++i) {
        dl += c[i] * (m - i);
    }
    for (int i = m + 1; i <= n; ++i) {
        dr += c[i] * (i - m);
    }
    if (p1 < m) {
        dl += s1 * (m - p1);
    } else if (p1 > m) {
        dr += s1 * (p1 - m);
    }
    long long best = 1e18;
    for (int i = 1; i <= n; ++i) {
        long long d = dl - dr;
        if (i < m) {
            d += s2 * (m - i);
        } else if (i > m) {
            d -= s2 * (i - m);
        }
        d = d > 0 ? d : -d;
        if (d < best) {
            best = d, p2 = i;
        }
    }
    cout << p2 << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}