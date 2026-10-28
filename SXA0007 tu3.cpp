#include <bits/stdc++.h>
using namespace std;

int n, i, j;

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (j = 1; j <= n; j++) {
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}
