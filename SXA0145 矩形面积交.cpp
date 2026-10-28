#include <bits/stdc++.h>
using namespace std;
double x1, q1, x2, q2, x3, q3, x4, q4, w, h, t;
signed main() {
    scanf("%lf%lf%lf%lf", &x1, &q1, &x2, &q2);
    scanf("%lf%lf%lf%lf", &x3, &q3, &x4, &q4);
    if (x1 > x2) {
        t = x1, x1 = x2, x2 = t;
    }
    if (q1 > q2) {
        t = q1, q1 = q2, q2 = t;
    }
    if (x3 > x4) {
        t = x3, x3 = x4, x4 = t;
    }
    if (q3 > q4) {
        t = q3, q3 = q4, q4 = t;
    }
    w = min(x2, x4) - max(x1, x3);
    h = min(q2, q4) - max(q1, q3);
    if (w < 0) {
        w = 0;
    }
    if (h < 0) {
        h = 0;
    }
    printf("%.2f\n", w * h);
    return 0;
}
