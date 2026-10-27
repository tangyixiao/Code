#include <bits/stdc++.h>
using namespace std;

int c[15][15];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        c[i][1] = 1;
        c[i][i] = 1;
        for (int j = 2; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cout << "\n";
            for (int s = 1; s <= 3 * (n - i) + 1; s++) {
                cout << " ";
            }
        }
        for (int j = 1; j <= i; j++) {
            cout << setw(6) << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}
