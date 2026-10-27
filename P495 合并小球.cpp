#include <bits/stdc++.h>
using namespace std;

long long a, b, g, h, t, d;

signed main() {
    if (fopen("ball.in", "r")) {
        freopen("ball.in", "r", stdin);
        freopen("ball.out", "w", stdout);
    }
    cin >> a >> b;
    for (g = a, h = b; h; t = g, g = h, h = t) {
        g %= h;
    }
    d = (a + b) / g;
    if (d & (d - 1)) {
        cout << "-1\n";
        return 0;
    }
    for (d >>= 1; d; d >>= 1) {
        t++;
    }
    cout << t << "\n";
    return 0;
}