#include <bits/stdc++.h>
using namespace std;

int i;
double x, s, t, sg, p;

double arctanx(double v) {
    double sum = 0, item = v, pw = v, sign = 1;
    int k = 1;
    for (; fabs(item) >= 1e-6;) {
        sum += item;
        pw *= v * v;
        k += 2;
        sign = -sign;
        item = sign * pw / k;
    }
    return sum;
}

signed main() {
    x = 1 / sqrt(3.0);
    s = 6 * arctanx(x);
    cout << fixed << setprecision(10) << s << "\n";
    return 0;
}
