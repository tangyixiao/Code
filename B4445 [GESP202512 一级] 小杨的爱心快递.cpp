#include <bits/stdc++.h>
using namespace std;
double v, g, m, n, ans1, ans2;
signed main() {
    cin >> v >> g >> m >> n;
    ans1 = v * 0.5;
    ans2 = (g < 300 ? m : n);
    cout << fixed << setprecision(1) << min(ans1, ans2);
    return 0;
}