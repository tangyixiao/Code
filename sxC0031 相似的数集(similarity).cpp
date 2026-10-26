#include <bits/stdc++.h>
using namespace std;

const int N = 55, M = 1e3 + 5;
int n, k, len[N], a[N][M];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> len[i];
        for (int j = 1; j <= len[i]; j++) {
            cin >> a[i][j];
        }
        sort(a[i] + 1, a[i] + len[i] + 1);
        len[i] = unique(a[i] + 1, a[i] + len[i] + 1) - a[i] - 1;
    }
    cin >> k;
    for (; k--;) {
        int x, y, p = 1, q = 1, nc = 0;
        cin >> x >> y;
        for (; p <= len[x] && q <= len[y];) {
            if (a[x][p] == a[y][q]) {
                nc++;
                p++;
                q++;
            } else if (a[x][p] < a[y][q]) {
                p++;
            } else {
                q++;
            }
        }
        int nt = len[x] + len[y] - nc;
        cout << fixed << setprecision(2) << nc * 100.0 / nt << "%\n";
    }
    return 0;
}
