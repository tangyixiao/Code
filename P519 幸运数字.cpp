#include <bits/stdc++.h>
using namespace std;

typedef unsigned __int128 u128;
char s[25];
u128 f[2][2][2], g[2][2][2];
int len;

void put(u128 v) {
    char buf[50];
    int p = 0;
    if (v == 0) {
        printf("0\n");
        return;
    }
    while (v > 0) {
        buf[p++] = '0' + (int)(v % 10);
        v /= 10;
    }
    for (int i = p - 1; i >= 0; i--) {
        printf("%c", buf[i]);
    }
    printf("\n");
}

signed main() {
    scanf("%s", s);
    len = strlen(s);
    f[1][0][0] = 1;
    for (int i = 0; i < len; i++) {
        memset(g, 0, sizeof(g));
        int lim = s[i] - '0';
        for (int t = 0; t < 2; t++) {
            for (int h = 0; h < 2; h++) {
                for (int l4 = 0; l4 < 2; l4++) {
                    if (f[t][h][l4] == 0) {
                        continue;
                    }
                    int up = t ? lim : 9;
                    for (int d = 0; d <= up; d++) {
                        int nh = h;
                        if (l4 == 1 && d == 9) {
                            nh = 1;
                        }
                        int nt = 0;
                        if (t == 1 && d == lim) {
                            nt = 1;
                        }
                        int nl = 0;
                        if (d == 4) {
                            nl = 1;
                        }
                        g[nt][nh][nl] += f[t][h][l4];
                    }
                }
            }
        }
        memcpy(f, g, sizeof(g));
    }
    put(f[0][1][0] + f[0][1][1] + f[1][1][0] + f[1][1][1]);
    return 0;
}
