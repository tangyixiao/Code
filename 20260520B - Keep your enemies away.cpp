#include <bits/stdc++.h>
using namespace std;
int n, h;
signed main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> h >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        h -= x;
        if (h <= 0) {
            cout << "Yes\n";
            exit(0);
        }
    }
    cout << "No\n";
    return 0;
}