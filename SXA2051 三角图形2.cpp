#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    char c;
    int t, k;
    cin >> n >> c >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        if (t == 1) {
            for (int j = 1; j <= i; j++) {
                cout << c;
            }
        } else {
            for (int j = 1; j <= i; j++) {
                if (i == n || j == 1 || j == i) {
                    cout << c;
                } else {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
