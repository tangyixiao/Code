#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int k = 1; k <= 2 * n - 1; k++) {
        int m = k <= n ? k : 2 * n - k;
        int l = n - m, r = 2 * n - 3 + m;
        for (int j = 0; j <= r; j++) {
            if (k == 1 || k == 2 * n - 1) {
                cout << (j >= l && j <= r ? '*' : ' ');
            } else {
                cout << (j == l || j == r ? '*' : ' ');
            }
        }
        cout << "\n";
    }
    return 0;
}
