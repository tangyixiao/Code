#include <bits/stdc++.h>
using namespace std;

double x1, b1, x2, y2;

signed main() {
    cin >> x1 >> b1 >> x2 >> y2;
    printf("%.2f\n", max(fabs(x1 - x2), fabs(b1 - y2)));
    return 0;
}