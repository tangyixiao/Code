#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int w, x, h, xx1, xx2, yy1, yy2, zz1, zz2, q, ans;
bool vis[N][N][N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> w >> x >> h;
    cin >> q;
    for (int _ = 1; _ <= q; _++) {
        cin >> xx1 >> yy1 >> zz1 >> xx2 >> yy2 >> zz2;
        for (int i = xx1; i <= xx2; i++) {
            for (int j = yy1; j <= yy2; j++) {
                for (int k = zz1; k <= zz2; k++) {
                    vis[i][j][k] = true;
                }
            }
        }
    }
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; k++) {
                if (!vis[i][j][k]) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}