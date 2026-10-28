#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, a, b, cc, dd;
int p[N][N], s[N][N], t[N][N], mm[N][N], dq[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> a >> b >> cc >> dd;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + x;
        }
    }
    int nr = n - a + 1, mc = m - b + 1;
    for (int i = 1; i <= nr; i++) {
        for (int j = 1; j <= mc; j++) {
            s[i][j] = p[i + a - 1][j + b - 1] - p[i - 1][j + b - 1] - p[i + a - 1][j - 1] + p[i - 1][j - 1];
        }
    }
    int ht = a - cc - 1, wt = b - dd - 1;
    int nrow = n - cc + 1, ncol = m - dd + 1;
    for (int i = 1; i <= nrow; i++) {
        for (int j = 1; j <= ncol; j++) {
            t[i][j] = p[i + cc - 1][j + dd - 1] - p[i - 1][j + dd - 1] - p[i + cc - 1][j - 1] + p[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= nrow; i++) {
        int h = 0, tl = -1;
        for (int j = 1; j <= ncol; j++) {
            while (h <= tl && t[i][dq[tl]] >= t[i][j]) {
                tl--;
            }
            dq[++tl] = j;
            while (dq[h] < j - wt + 1) {
                h++;
            }
            if (j >= wt) {
                t[i][j - wt + 1] = t[i][dq[h]];
            }
        }
    }
    int ncol2 = ncol - wt + 1;
    for (int j = 1; j <= ncol2; j++) {
        int h = 0, tl = -1;
        for (int i = 1; i <= nrow; i++) {
            while (h <= tl && t[dq[tl]][j] >= t[i][j]) {
                tl--;
            }
            dq[++tl] = i;
            while (dq[h] < i - ht + 1) {
                h++;
            }
            if (i >= ht) {
                mm[i - ht + 1][j] = t[dq[h]][j];
            }
        }
    }
    int ans = -1000000000;
    for (int i = 1; i <= nr; i++) {
        for (int j = 1; j <= mc; j++) {
            int v = s[i][j] - mm[i + 1][j + 1];
            if (v > ans) {
                ans = v;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
