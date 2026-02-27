#include <bits/stdc++.h>
using namespace std;
double x, y, n, p, ans1, ans2;
signed main() {
    cin >> x >> y >> n >> p;
    ans1 = (p >= x ? -y : 0) + p;
    ans2 = n * p / 10;
    cout << fixed << setprecision(2) << min(ans1, ans2);
    return 0;
}