#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
char s[N], t[N], best[N];
int n, k, i, j, d, c, p[N], cost, bc, bd;
bool cmp(int u, int v) {
    int cu = abs(s[u] - '0' - d), cv = abs(s[v] - '0' - d);
    if (cu != cv) {
        return cu < cv;
    }
    int gu = s[u] - '0' > d, gv = s[v] - '0' > d;
    if (gu != gv) {
        return gu > gv;
    }
    if (gu) {
        return u < v;
    }
    return u > v;
}
signed main() {
    scanf("%d%d%s", &n, &k, s);
    bc = -1;
    for (d = 0; d <= 9; d++) {
        for (i = 0; i < n; i++) {
            p[i] = i;
        }
        sort(p, p + n, cmp);
        for (i = 0; i < n; i++) {
            t[i] = s[i];
        }
        cost = 0;
        for (i = 0; i < k; i++) {
            cost += abs(s[p[i]] - '0' - d);
            t[p[i]] = '0' + d;
        }
        if (bc == -1 || cost < bc || (cost == bc && strcmp(t, best) < 0)) {
            bc = cost, bd = d;
            for (i = 0; i < n; i++) {
                best[i] = t[i];
            }
            best[n] = 0;
        }
    }
    printf("%d\n%s\n", bc, best);
    return 0;
}
