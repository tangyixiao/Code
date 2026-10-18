#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N], c[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (m > 0 && a[i] == b[m]) {
            c[m]++;
            continue;
        }
        b[++m] = a[i], c[m] = 1;
    }
    long long t = 0;
    int cur = 0;
    for (int i = 1; i <= m; i++) {
        t += 6LL * (b[i] - cur) + 5 + c[i];
        cur = b[i];
    }
    t += 4LL * cur;
    cout << t << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}