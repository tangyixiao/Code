#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 55;
const int INF = 1e9;
char s[N];
int m, len;
int f[N][M];

signed main() {
    scanf("%s", s);
    scanf("%d", &m);
    len = strlen(s);
    for (int i = 0; i <= len; i++) {
        for (int r = 0; r < m; r++) {
            f[i][r] = INF;
        }
    }
    f[0][0] = 0;
    for (int i = 0; i < len; i++) {
        int val = 0;
        for (int j = i + 1; j <= len; j++) {
            val = (val * 10 + (s[j - 1] - '0')) % m;
            for (int r = 0; r < m; r++) {
                if (f[i][r] >= INF) {
                    continue;
                }
                int nr;
                if (i == 0) {
                    nr = val;
                } else {
                    nr = (int)((long long)r * val % m);
                }
                if (f[i][r] + 1 < f[j][nr]) {
                    f[j][nr] = f[i][r] + 1;
                }
            }
        }
    }
    int mn = -1, mx = -1;
    for (int r = 0; r < m; r++) {
        if (f[len][r] < INF) {
            if (mn < 0) {
                mn = r;
            }
            mx = r;
        }
    }
    printf("%d %d %d %d\n", mn, f[len][mn] - 1, mx, f[len][mx] - 1);
    return 0;
}
