#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 200010;
const double eps = 1e-7;
const double PI = acos(-1.0);

bool eq(double x, double y) { return x - y < eps && y - x < eps; }

struct V {
    double x, y;
    V(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    V operator+(const V &o) const { return V(x + o.x, y + o.y); }
    V operator-(const V &o) const { return V(x - o.x, y - o.y); }
    V operator*(double k) const { return V(x * k, y * k); }
    double d(const V &o) const { return x * o.x + y * o.y; }
    double c(const V &o) const { return x * o.y - y * o.x; }
};

V P[N];
double S0, S1, rho;
int n;
V C[N];
double A[N], T[N];
V G;
double ans, ag;

double ar(const V &a, const V &b, const V &c) {
    return fabs((b - a).c(c - a)) * 0.5;
}
V ct(const V &a, const V &b, const V &c) {
    return (a + b + c) * (1.0 / 3);
}
double ar(const V &a, const V &b, const V &c, const V &d) {
    return ar(a, b, c) + ar(a, c, d);
}
V ct(const V &a, const V &b, const V &c, const V &d) {
    return ct(a, b, c) * ar(a, b, c) + ct(a, c, d) * ar(a, c, d);
}

double sA(int l, int r) {
    if (l <= r)
        return A[r] - A[l] - ar(P[1], P[l], P[r]);
    else
        return A[n] - sA(r, l);
}
V sC(int l, int r) {
    if (l <= r)
        return C[r] - C[l] - ct(P[1], P[l], P[r]) * ar(P[1], P[l], P[r]);
    else
        return C[n] - sC(r, l);
}

double tr(const V &a, const V &b, const V &c, const V &d, double x0, double y0, double x) {
    V p1 = a + (b - a) * x0;
    V p2 = c + (d - c) * y0;
    V p3 = a + (b - a) * x;
    double t1 = (p3 - p1).c(p2 - p1);
    double t2 = (d - c).c(p3 - p2);
    if (eq(t2, 0))
        return 1e50;
    return t1 / t2 + y0;
}

void ini() {
    for (int i = 3; i <= n; ++i) {
        T[i] = ar(P[i], P[i - 1], P[1]);
        A[i] = A[i - 1] + T[i];
        C[i] = C[i - 1] + ct(P[i], P[i - 1], P[1]) * T[i];
    }
    G = C[n] * (1.0 / A[n]);
}

double sg(int l, int r, double x, double y) {
    V p1 = P[l] + (P[l + 1] - P[l]) * x;
    V p2 = P[r] + (P[r + 1] - P[r]) * y;
    double a1 = sA(l % n + 1, r);
    double a2 = ar(p1, P[l + 1], P[r], p2);
    V c1 = sC(l % n + 1, r);
    V c2 = ct(p1, P[l + 1], P[r], p2);
    double at = a1 + a2;
    V ct = (c1 + c2) * (1.0 / at);
    return (ct - G).d(p2 - p1);
}

double ga(const V &p1, const V &p2) {
    double res = 2 * PI - atan2(p2.y - p1.y, p2.x - p1.x);
    if (res < -eps)
        res += 2 * PI;
    if (res > 2 * PI - eps)
        res -= 2 * PI;
    return res;
}

void up(int l, int r, double x, double y) {
    V p1 = P[l] + (P[l + 1] - P[l]) * x;
    V p2 = P[r] + (P[r + 1] - P[r]) * y;
    double a1 = sA(l % n + 1, r);
    double a2 = ar(p1, P[l + 1], P[r], p2);
    V c1 = sC(l % n + 1, r);
    V c2 = ct(p1, P[l + 1], P[r], p2);
    double at = a1 + a2;
    V ct = (c1 + c2) * (1.0 / at);
    double len = sqrt((p1 - p2).d(p1 - p2));
    double h1 = (ct - p1).c(p2 - p1) / len;
    double h2 = (p2 - p1).c(G - p1) / len;
    double s = h1 * S1 + h2 * S0 * rho;
    if (s < ans) {
        ans = s;
        ag = ga(p1, p2);
    }
}

void ca(int l, int r, double x0, double x1, double y0) {
    double y1 = tr(P[l], P[l + 1], P[r], P[r + 1], x0, y0, x1);
    double s0 = sg(l, r, x0, y0);
    double s1 = sg(l, r, x1, y1);
    if (eq(s0, 0))
        up(l, r, x0, y0);
    else if (eq(s1, 0))
        up(l, r, x1, y1);
    else if (s0 * s1 < 0) {
        while (x1 - x0 > 1e-8) {
            double xm = (x0 + x1) / 2;
            double ym = tr(P[l], P[l + 1], P[r], P[r + 1], x0, y0, xm);
            double sm = sg(l, r, xm, ym);
            if (s0 * sm < 0) {
                x1 = xm;
                y1 = ym;
                s1 = sm;
            } else {
                x0 = xm;
                y0 = ym;
                s0 = sm;
            }
        }
        up(l, r, x0, y0);
    }
}

void sv() {
    scanf("%d%lf", &n, &rho);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", &P[i].x, &P[i].y);
    P[0] = P[n];
    P[n + 1] = P[1];
    ini();
    S0 = A[n];
    S1 = S0 * rho;
    int l = 1, r;
    for (r = 1; r <= n && A[r + 1] < S1 + eps; ++r)
        ;
    double kl = 0, kr = (S1 - A[r]) / (A[r + 1] - A[r]);
    ans = 1e50;
    for (;;) {
        double tl = tr(P[r], P[r + 1], P[l], P[l + 1], kr, kl, 1);
        double trr = tr(P[l], P[l + 1], P[r], P[r + 1], kl, kr, 1);
        if (tl < 1 + eps) {
            ca(l, r, kl, tl, kr);
            r = r % n + 1;
            kr = 0;
            kl = tl;
        } else {
            ca(l, r, kl, 1, kr);
            l = l % n + 1;
            kl = 0;
            kr = trr;
            if (l == 1)
                break;
        }
    }
    printf("%.10f\n", ag);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        sv();
    return 0;
}