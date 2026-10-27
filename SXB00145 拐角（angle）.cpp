#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5;
int n, a[N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = min(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
