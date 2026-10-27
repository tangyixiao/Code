#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, i, j, k, s, b, r, c, ok;
int len[N], f[N];
char t[105];
signed main() {
    if (scanf("%s", t) != 1) {
        return 0;
    }
    ok = 1, n = 0;
    for (i = 0; t[i]; i++) {
        if (t[i] < '0' || t[i] > '9') {
            ok = 0;
        } else {
            n = n * 10 + t[i] - '0';
        }
    }
    if (!ok) {
        n = strlen(t);
    }
    m = 0;
    while (scanf("%s", t) == 1) {
        m++, len[m] = strlen(t);
    }
    f[0] = 0;
    for (i = 1; i <= m; i++) {
        f[i] = 1e9, s = 0;
        for (j = i; j >= 1; j--) {
            s += len[j], k = i - j + 1;
            if (k == 1) {
                c = (s == n) ? 0 : 500;
            } else {
                if (n - s < k - 1) {
                    break;
                }
                b = (n - s) / (k - 1), r = (n - s) % (k - 1);
                c = (k - 1 - r) * (b - 1) * (b - 1) + r * b * b;
            }
            if (f[j - 1] + c < f[i]) {
                f[i] = f[j - 1] + c;
            }
        }
    }
    printf("Minimal badness is %d.\n", f[m]);
    return 0;
}
