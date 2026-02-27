#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, ans;
bool vis[105][105];
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && abs(dx) + abs(dy) <= 2) {
                    vis[nx][ny] = true;
                }
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                    vis[nx][ny] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j] == false) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
