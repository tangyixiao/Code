#include <bits/stdc++.h>
using namespace std;

int h, w, i, j, s, t, ok;
char a[35][35], b[35][35];

signed main() {
    scanf("%d %d", &h, &w);
    for (i = 0; i < h; i++) {
        scanf("%s", a[i]);
    }
    for (i = 0; i < h; i++) {
        scanf("%s", b[i]);
    }
    ok = 0;
    for (s = 0; s < h; s++) {
        for (t = 0; t < w; t++) {
            int good = 1;
            for (i = 0; i < h; i++) {
                for (j = 0; j < w; j++) {
                    int ni = ((i - s) % h + h) % h;
                    int nj = ((j - t) % w + w) % w;
                    if (a[ni][nj] != b[i][j]) {
                        good = 0;
                    }
                }
            }
            if (good == 1) {
                ok = 1;
            }
        }
    }
    if (ok == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
