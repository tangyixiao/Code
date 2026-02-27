//eps
#include <bits/stdc++.h>
using namespace std;
long double h, w;
signed main() {
    cin >> h >> w;
    cout << fixed << setprecision(6) << max(min(max(h, w) / 3.0, min(h, w)), min(h, w) / 2.0);
    return 0;
}