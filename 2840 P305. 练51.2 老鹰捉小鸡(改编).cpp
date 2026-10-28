#include <bits/stdc++.h>
using namespace std;

int n, i, j;

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cout << i << ":";
        for (j = 0; j < n; j++) {
            cout << (i - 1 + j) % n + 1;
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
