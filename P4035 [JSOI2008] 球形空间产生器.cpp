#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const double eps = 1e-7;
int n;
double a[N][N], b[N], c[N][N];
inline void gauss() {
    for (int i = 1; i <= n; i++) {  // 找到x[i]系数不为0的一个方程
        for (int j = i; j <= n; j++) {
            if (fabs(c[j][i] > 1e-8)) {
                for (int k = 1; k <= n; k++)
                    swap(c[i][k], c[j][k]);
                swap(b[i], b[j]);
            }
        }
        // 消去其他方程x[i]的系数
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            double rate = c[j][i] / c[i][i];
            for (int k = i; k <= n; k++)
                c[j][k] -= c[i][k] * rate;
            b[j] -= b[i] * rate;
        }
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 2 * (a[i][j] - a[i + 1][j]);
            b[i] += a[i][j] * a[i][j] - a[i + 1][j] * a[i + 1][j];
        }
    }
    gauss();
    for (int i = 1; i <= n; i++) {
        printf("%.3lf ", b[i] / c[i][i]);
    }
    return 0;
}