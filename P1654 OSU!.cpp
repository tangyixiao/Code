#include <bits/stdc++.h>
using namespace std;
const int N = 114514;
int n;
double x1[N], x2[N], p[N], ans[N];
inline void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
    }
    return;
}

inline void output() {
    printf("%.1lf", ans[n]);
    return;
}
inline void solve() {
    input();
    for (int i = 1; i <= n; i++) {
        x1[i] = (x1[i - 1] + 1) * p[i];
        x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * p[i];
        ans[i] = ans[i - 1] + (3 * (x1[i - 1] + x2[i - 1]) + 1) * p[i];
    }
    output();
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}