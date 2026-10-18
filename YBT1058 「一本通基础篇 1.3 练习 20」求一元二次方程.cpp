#include <bits/stdc++.h>
using namespace std;

double a, b, c, dt, x1, x2;

inline void input() {
    cin >> a >> b >> c;
}

inline void solve() {
    dt = b * b - 4 * a * c;
    if (dt < 0) {
        cout << "No answer!\n";
        return;
    }
    dt = sqrt(dt);
    x1 = (-b + dt) / (2 * a);
    x2 = (-b - dt) / (2 * a);
    if (x1 > x2) {
        swap(x1, x2);
    }
    if (x1 == x2) {
        printf("x1=x2=%.5f\n", x1);
    } else {
        printf("x1=%.5f;x2=%.5f\n", x1, x2);
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
