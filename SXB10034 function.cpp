#include <bits/stdc++.h>
using namespace std;

long long x, y, z;
long long f[25][25][25];
bool vis[25][25][25];

long long c(long long a, long long b, long long d) {
    if (min(a, min(b, d)) < 0) {
        return 1;
    }
    if (max(a, max(b, d)) > 20) {
        return c(20, 20, 20);
    }
    if (vis[a][b][d]) {
        return f[a][b][d];
    }
    long long res;
    if (a < b && b < d) {
        res = c(a, b, d - 1) + c(a, b - 1, d - 1) + c(a, b - 1, d);
    } else {
        res = c(a - 1, b, d) + c(a - 1, b - 1, d) + c(a - 1, b, d - 1) - c(a - 1, b - 1, d - 1);
    }
    vis[a][b][d] = true;
    f[a][b][d] = res;
    return res;
}

signed main() {
    FILE *fp = fopen("function.in", "r");
    if (fp != NULL) {
        fclose(fp);
        freopen("function.in", "r", stdin);
        freopen("function.out", "w", stdout);
    }
    cin >> x >> y >> z;
    cout << c(x, y, z) << "\n";
    return 0;
}
