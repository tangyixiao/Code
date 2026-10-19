#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

double a, b, c, d, rt[N];
int cnt;

inline double f(double x) {
    return ((a * x + b) * x + c) * x + d;
}

inline void input() {
    cin >> a >> b >> c >> d;
}

inline void bis(double l, double r) {
    double m = 0;
    for (int i = 1; i <= 60; i++) {
        m = (l + r) / 2;
        if (f(l) * f(m) <= 0) {
            r = m;
        } else {
            l = m;
        }
    }
    rt[++cnt] = (l + r) / 2;
}

inline void solve() {
    for (int i = -100000; i <= 100000; i++) {
        double x = i / 1000.0, y = f(x);
        if (fabs(y) < 1e-7) {
            rt[++cnt] = x, i += 2;
        } else if (y * f(x + 0.001) < 0) {
            bis(x, x + 0.001);
        }
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = i + 1; j <= cnt; j++) {
            if (rt[j] < rt[i]) {
                swap(rt[i], rt[j]);
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        printf("%.2f%s", rt[i], i == cnt ? "\n" : " ");
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
