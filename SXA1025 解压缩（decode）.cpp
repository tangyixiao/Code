#include <bits/stdc++.h>
using namespace std;

int n, x, f;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        for (int j = 1; j <= x; j++) {
            if (f) {
                cout << " ";
            }
            cout << (i % 2 == 1 ? 1 : 0);
            f = 1;
        }
    }
    cout << "\n";
    return 0;
}
