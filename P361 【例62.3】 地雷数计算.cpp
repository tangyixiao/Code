#include <bits/stdc++.h>
using namespace std;

const int N = 105;
char a[N][N], b[N][N];
int n, m;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (a[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] = a[i][j] == '*' ? '*' : '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != '*') {
                continue;
            }
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x < 1 || y < 1 || x > n || y > m || (x == i && y == j)) {
                        continue;
                    }
                    if (b[x][y] != '*') {
                        b[x][y]++;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        b[i][m + 1] = 0;
        cout << b[i] + 1 << "\n";
    }
    return 0;
}