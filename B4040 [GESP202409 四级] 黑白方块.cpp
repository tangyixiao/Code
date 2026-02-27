#include <bits/stdc++.h>
using namespace std;
int main() {
    int s[4][4] = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0};
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool d = 0;
        int a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%1d", &a[i][j]);
            }
        }
        for (int i = 0; i + 3 < n; i++) {
            for (int j = 0; j + 3 < m; j++) {
                bool p = 1;
                for (int x = 0; x < 4; x++) {
                    for (int y = 0; y < 4; y++) {
                        if (s[x][y] != a[i + x][j + y])
                            p = 0;
                    }
                }
                if (p)
                    d = 1;
            }
        }
        if (d) {
            cout << "Yes\n";
        } else
            cout << "No\n";
    }
}
