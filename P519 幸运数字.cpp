#include <bits/stdc++.h>
using namespace std;

typedef unsigned __int128 u128;
char s[40];
u128 f[2][2][2], g[2][2][2];
int len;

void put(u128 v) {
    char buf[60];
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
    freopen("lucky.in", "r", stdin);
    freopen("lucky.out", "w", stdout);
    scanf("%s", s);
    len = strlen(s);
    f[1][0][0] = 1;
    for (int i = 0; i < len; i++) {
        memset(g, 0, sizeof(g));
        int lim = s[i] - '0';
        for (int t = 0; t < 2; t++) {
            for (int p = 0; p < 2; p++) {
                for (int fd = 0; fd < 2; fd++) {
                    if (f[t][p][fd] == 0) {
                        continue;
                    }
                    int up = t ? lim : 9;
                    for (int d = 0; d <= up; d++) {
                        int nt = (t == 1 && d == lim) ? 1 : 0;
                        int nfd = fd;
                        if (p == 1 && d == 9) {
                            nfd = 1;
                        }
                        int np = (d == 4) ? 1 : 0;
                        g[nt][np][nfd] += f[t][p][fd];
                    }
                }
            }
        }
        memcpy(f, g, sizeof(g));
    }
    put(f[0][0][1] + f[0][1][1] + f[1][0][1] + f[1][1][1]);
    return 0;
}
