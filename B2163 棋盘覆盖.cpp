#include <bits/stdc++.h>
using namespace std;
int n, cnt, h, a, b, mp[2010][2010];
void dfs(int x, int y, int tx, int ty, int k) {
    if (k == 1) { // 直接返回
        return;
    }
    int s = k / 2, num = ++cnt;
    if (tx < x + s && ty < y + s) { // 在左上角
        dfs(x, y, tx, ty, s);
    } else { // 不在左上角
        mp[x + s - 1][y + s - 1] = num;
        dfs(x, y, x + s - 1, y + s - 1, s);
    }
    if (tx < x + s && ty >= y + s) { // 同理
        dfs(x, y + s, tx, ty, s);
    } else {
        mp[x + s - 1][y + s] = num;
        dfs(x, y + s, x + s - 1, y + s, s);
    }
    if (tx >= x + s && ty < y + s) {
        dfs(x + s, y, tx, ty, s);
    } else {
        mp[x + s][y + s - 1] = num;
        dfs(x + s, y, x + s, y + s - 1, s);
    }
    if (tx >= x + s && ty >= y + s) {
        dfs(x + s, s + y, tx, ty, s);
    } else {
        mp[x + s][y + s] = num;
        dfs(x + s, y + s, x + s, y + s, s);
    }
}
int main() {
    cin >> n >> a >> b;
    n = 1 << n;
    dfs(1, 1, a, b, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
