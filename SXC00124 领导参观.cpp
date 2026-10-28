#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, m, i;
int x[N], y[N];
double dis[N];

signed main() {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    double hi = 0;
    for (i = 1; i < n; i++) {
        dis[i] = sqrt(1.0 * (x[i + 1] - x[i]) * (x[i + 1] - x[i]) + 1.0 * (y[i + 1] - y[i]) * (y[i + 1] - y[i]));
        if (dis[i] > hi) {
            hi = dis[i];
        }
    }
    double lo = 0;
    for (int it = 0; it < 100; it++) {
        double mid = (lo + hi) / 2;
        int seg = 1;
        for (i = 1; i < n; i++) {
            if (dis[i] > mid) {
                seg++;
            }
        }
        if (seg <= m) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%.2f\n", hi);
    return 0;
}
