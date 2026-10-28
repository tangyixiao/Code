#include <bits/stdc++.h>
using namespace std;

int t;
long long p, a, b, c;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> p >> a >> b >> c;
        if (b == 0) {
            if (c == 0) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        } else {
            cout << "YES" << "\n";
        }
    }
    return 0;
}
