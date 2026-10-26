#include <bits/stdc++.h>
using namespace std;
int n, i, j;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i - 1; j++) {
            cout << " ";
        }
        for (j = 1; j <= 2 * (n - i) + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
