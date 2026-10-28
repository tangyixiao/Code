#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i, tot;
long long x[N], y[N], ans, save, best;

long long d(int i, int j) {
    long long dx = x[i] - x[j];
    long long dy = y[i] - y[j];
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    return dx + dy;
}

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    tot = 0;
    for (i = 2; i <= n; i++) {
        tot += d(i - 1, i);
    }
    best = 0;
    for (i = 2; i < n; i++) {
        save = d(i - 1, i) + d(i, i + 1) - d(i - 1, i + 1);
        if (save > best) {
            best = save;
        }
    }
    ans = tot - best;
    cout << ans << "\n";
    return 0;
}
