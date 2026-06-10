#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
struct P {
    double x, y;
} p[44444], s[44444];
bool cmp(P a, P b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
double cross(P a, P b, P c) { return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }
double dis(P a, P b) { return hypot(a.x - b.x, a.y - b.y); }
int main() {
    int n, m = 0;
    double a, b, r;
    scanf("%d%lf%lf%lf", &n, &a, &b, &r);
    double dx = b / 2 - r, dy = a / 2 - r;
    double cs[4] = {1, -1, -1, 1}, sn[4] = {1, 1, -1, -1};
    while (n--) {
        double x, y, t;
        scanf("%lf%lf%lf", &x, &y, &t);
        double ct = cos(t), st = sin(t);
        for (int i = 0; i < 4; ++i) {
            double xx = dx * cs[i] * ct - dy * sn[i] * st;
            double yy = dx * cs[i] * st + dy * sn[i] * ct;
            p[m++] = {x + xx, y + yy};
        }
    }
    sort(p, p + m, cmp);
    int tp = 0;
    for (int i = 0; i < m; ++i) {
        while (tp > 1 && cross(s[tp - 2], s[tp - 1], p[i]) <= 0)
            --tp;
        s[tp++] = p[i];
    }
    int k = tp;
    for (int i = m - 2; i >= 0; --i) {
        while (tp > k && cross(s[tp - 2], s[tp - 1], p[i]) <= 0)
            --tp;
        s[tp++] = p[i];
    }
    double ans = 2 * PI * r;
    for (int i = 1; i < tp; ++i)
        ans += dis(s[i - 1], s[i]);
    printf("%.2f\n", ans);
    return 0;
}