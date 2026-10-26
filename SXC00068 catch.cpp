#include <bits/stdc++.h>
using namespace std;
const int N = 15;
char g[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int px[2], py[2], pd[2];
void mv(int k) {
    int x = px[k] + dx[pd[k]], y = py[k] + dy[pd[k]];
    if (x < 1 || x > 10 || y < 1 || y > 10 || g[x][y] == '*') {
        pd[k] = (pd[k] + 1) % 4;
    } else {
        px[k] = x;
        py[k] = y;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'C') {
                px[0] = i;
                py[0] = j;
            }
            if (g[i][j] == 'M') {
                px[1] = i;
                py[1] = j;
            }
        }
    }
    int t = 0, ans = -1;
    for (; t < 200000; t++) {
        mv(0);
        mv(1);
        if (px[0] == px[1] && py[0] == py[1]) {
            ans = t + 1;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
