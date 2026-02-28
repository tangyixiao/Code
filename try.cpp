#include <bits/stdc++.h>
using namespace std;
int n, m, d, a[25][25];
bool vis[405];
int main() {
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = -1;
    for (int i1 = 1; i1 <= n; i1++) {
        for (int i2 = i1; i2 <= n; i2++) {
            for (int j1 = 1; j1 <= m; j1++) {
                for (int j2 = j1; j2 <= m; j2++) {
                    memset(vis, 0, sizeof(vis));
                    int cnt = 0;
                    for (int i = i1; i <= i2; i++) {
                        for (int j = j1; j <= j2; j++) {
                            if (!vis[a[i][j]]) {
                                vis[a[i][j]] = true;
                                cnt++;
                            }
                        }
                    }
                    if (cnt == d) {
                        ans = max(ans, (i2 - i1 + 1) * (j2 - j1 + 1));
                    }
                }
            }
        }
    }
    if (ans == -1) {
        cout << "Hrk";
    } else {
        cout << ans;
    }
    return 0;
}