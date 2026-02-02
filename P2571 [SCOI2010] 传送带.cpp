#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, p, q, r;

inline double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double calc(double t1, double t2) {

    double Ex = Ax + (Bx - Ax) * t1;
    double Ey = Ay + (By - Ay) * t1;

    double Fx = Cx + (Dx - Cx) * t2;
    double Fy = Cy + (Dy - Cy) * t2;

    return dis(Ax, Ay, Ex, Ey) / p +
           dis(Ex, Ey, Fx, Fy) / r +
           dis(Fx, Fy, Dx, Dy) / q;
}

double ternary2(double t1) {
    double l = 0, r = 1;
    while (r - l > eps) {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if (calc(t1, mid1) < calc(t1, mid2)) {
            r = mid2;
        } else {
            l = mid1;
        }
    }
    return calc(t1, l);
}

double ternary1() {
    double l = 0, r = 1;
    while (r - l > eps) {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if (ternary2(mid1) < ternary2(mid2)) {
            r = mid2;
        } else {
            l = mid1;
        }
    }
    return ternary2(l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy >> p >> q >> r;

    cout << fixed << setprecision(2) << ternary1() << endl;
    return 0;
}