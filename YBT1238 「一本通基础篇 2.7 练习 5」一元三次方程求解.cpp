#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

double a, b, c, d, p[N], w[3];

inline double f(double x) {
    return ((a * x + b) * x + c) * x + d;
}

inline void input() {
    cin >> a >> b >> c >> d;
    return;
}

inline void solve() {
    int k = 0;
    p[k++] = -100;
    double g = b * b - 3 * a * c, t[2];
    if (g > 0) {
        t[0] = (-b - sqrt(g)) / (3 * a), t[1] = (-b + sqrt(g)) / (3 * a);
        if (t[0] > t[1]) {
            swap(t[0], t[1]);
        }
        for (int i = 0; i < 2; ++i) {
            if (t[i] > -100 && t[i] < 100) {
                p[k++] = t[i];
            }
        }
    }
    p[k++] = 100;
    int n = 0;
    for (int i = 0; i < k - 1; ++i) {
        double l = p[i], r = p[i + 1], m, fl = f(l);
        if (fl * f(r) > 0) {
            continue;
        }
        for (int j = 0; j < 100; ++j) {
            m = (l + r) / 2;
            if (fl * f(m) <= 0) {
                r = m;
            } else {
                l = m, fl = f(m);
            }
        }
        w[n++] = (l + r) / 2;
    }
    printf("%.2f %.2f %.2f\n", w[0], w[1], w[2]);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
