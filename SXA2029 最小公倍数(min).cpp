#include <bits/stdc++.h>
using namespace std;

int n, x, y;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        cout << x / __gcd(x, y) * y << "\n";
    }
    return 0;
}
