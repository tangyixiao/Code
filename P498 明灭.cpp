#include <bits/stdc++.h>
using namespace std;

const int N = 350;
int a[N][N];

signed main() {
    int ok = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }
    for (int s = 0; s <= 511; s++) {
        int b[4][4];
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                b[i][j] = a[i][j];
            }
        }
        int c = 0;
        for (int k = 0; k < 9; k++) {
            if (s >> k & 1) {
                int x = k / 3 + 1, y = k % 3 + 1;
                c++;
                b[x][y] ^= 1;
                if (x > 1) {
                    b[x - 1][y] ^= 1;
                }
                if (x < 3) {
                    b[x + 1][y] ^= 1;
                }
                if (y > 1) {
                    b[x][y - 1] ^= 1;
                }
                if (y < 3) {
                    b[x][y + 1] ^= 1;
                }
            }
        }
        int f = 1;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                if (b[i][j] != 1) {
                    f = 0;
                }
            }
        }
        if (f && (!ok || c < ok)) {
            ok = c;
        }
    }
    cout << ok << "\n";
    return 0;
}
