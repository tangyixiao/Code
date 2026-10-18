#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int m, n, a[N];

inline void input() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + n + 1);
    long long best = -1;
    int p = 0;
    for (int i = n; i >= 1; i--) {
        int c = min(m, n - i + 1);
        long long r = 1LL * a[i] * c;
        if (r > best) {
            best = r, p = a[i];
        }
    }
    cout << p << " " << best << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}