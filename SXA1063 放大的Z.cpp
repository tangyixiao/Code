#include <bits/stdc++.h>
using namespace std;

int n, i, j;

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        if (i == 1 || i == n) {
            for (j = 1; j <= n; j++) {
                cout << "*";
            }
        } else {
            for (j = 1; j < n - i + 1; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
