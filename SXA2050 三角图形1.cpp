#include <bits/stdc++.h>
using namespace std;

int n, t, i, j;
char c;

signed main() {
    cin >> n >> c >> t;
    if (t == 1) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                cout << c;
            }
            cout << "\n";
        }
    } else {
        for (i = 1; i <= n; i++) {
            if (i == 1) {
                cout << c;
            } else if (i == n) {
                for (j = 1; j <= n; j++) {
                    cout << c;
                }
            } else {
                cout << c;
                for (j = 1; j <= i - 2; j++) {
                    cout << " ";
                }
                cout << c;
            }
            cout << "\n";
        }
    }
    return 0;
}
