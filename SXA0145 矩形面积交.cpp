#include <bits/stdc++.h>
using namespace std;
double x1, y1, x2, y2, x3, y3, x4, y4, w, h, t;
signed main() {
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    scanf("%lf%lf%lf%lf", &x3, &y3, &x4, &y4);
    if (x1 > x2) {
        t = x1, x1 = x2, x2 = t;
    }
    if (y1 > y2) {
        t = y1, y1 = y2, y2 = t;
    }
    if (x3 > x4) {
        t = x3, x3 = x4, x4 = t;
    }
    if (y3 > y4) {
        t = y3, y3 = y4, y4 = t;
    }
    w = min(x2, x4) - max(x1, x3);
    h = min(y2, y4) - max(y1, y3);
    if (w < 0) {
        w = 0;
    }
    if (h < 0) {
        h = 0;
    }
    printf("%.2f\n", w * h);
    return 0;
}
