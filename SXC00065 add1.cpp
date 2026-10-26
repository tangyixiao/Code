#include <bits/stdc++.h>
using namespace std;

int T, n, i, k, c, ok;
int t[2005], b[2005], s[2005];

signed main() {
    scanf("%d", &T);
    while (T > 0) {
        T--;
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &t[i]);
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        for (i = 0; i < n; i++) {
            s[i] = t[i] + t[n - 1 - i];
        }
        ok = 0;
        for (k = 0; k <= 2000; k++) {
            int cc = -1, good = 1;
            for (i = 0; i < n; i++) {
                int rem = b[i] - k * s[i];
                if (rem < 0) {
                    good = 0;
                    break;
                }
                if (t[i] == 0) {
                    if (rem != 0) {
                        good = 0;
                        break;
                    }
                    continue;
                }
                if (rem % t[i] != 0) {
                    good = 0;
                    break;
                }
                if (cc == -1) {
                    cc = rem / t[i];
                } else if (cc != rem / t[i]) {
                    good = 0;
                    break;
                }
            }
            if (good && cc >= 0) {
                ok = 1;
                break;
            }
        }
        if (ok == 1) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
