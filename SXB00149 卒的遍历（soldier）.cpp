#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n, m, cnt, px[105], py[105];

void dfs(int x, int y, int step) {
    px[step] = x;
    py[step] = y;
    if (x == n && y == m) {
        cnt++;
        cout << cnt << ":";
        for (int i = 1; i <= step; i++) {
            cout << px[i] << "," << py[i];
            if (i < step) {
                cout << "->";
            }
        }
        cout << "\n";
        return;
    }
    if (x + 1 <= n) {
        dfs(x + 1, y, step + 1);
    }
    if (y + 1 <= m) {
        dfs(x, y + 1, step + 1);
    }
}

signed main() {
    cin >> n >> m;
    dfs(1, 1, 1);
    return 0;
}
