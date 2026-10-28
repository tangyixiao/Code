#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, cur, tot;
char h[N][64], o[64], u[64];

signed main() {
    scanf("%d", &n);
    cur = -1, tot = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%s", o);
        int ok = 1;
        if (o[0] == 'v') {
            scanf("%s", u);
            cur++, tot = cur;
            strcpy(h[cur], u);
        } else if (o[0] == 'b') {
            ok = cur > 0;
            if (ok) {
                cur--;
            }
        } else {
            ok = cur < tot;
            if (ok) {
                cur++;
            }
        }
        if (ok && cur >= 0) {
            printf("%s\n", h[cur]);
        } else {
            printf("?\n");
        }
    }
    return 0;
}
