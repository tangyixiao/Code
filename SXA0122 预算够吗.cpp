#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, s;

signed main() {
    cin >> n >> a >> b >> c;
    s = n - a - b - c;
    if (s >= 0) {
        cout << s << " YES" << "\n";
    } else {
        cout << -s << " NO" << "\n";
    }
    return 0;
}
