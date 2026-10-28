#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    double ans = n >= 10 ? n * 2.0 : n * 2.2;
    cout << fixed << setprecision(1) << ans << "\n";
    return 0;
}
