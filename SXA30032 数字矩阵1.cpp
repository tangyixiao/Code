#include <bits/stdc++.h>
using namespace std;

int n, i, j, v;

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            v = min(i, j);
            if (j > 1) {
                cout << " ";
            }
            cout << v;
        }
        cout << "\n";
    }
    return 0;
}
