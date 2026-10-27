#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, i, j, x, y, t, tot;
int l[N], r[N], tt[N], ord[N], put[N], pre[N];

bool cmp(int a, int b) {
    if (r[a] != r[b]) {
        return r[a] < r[b];
    }
    return l[a] < l[b];
}

int cntin(int a, int b) {
    if (a < 1) {
        a = 1;
    }
    if (b > 1000) {
        b = 1000;
    }
    int s = 0;
    for (int k = a; k <= b; k++) {
        s += put[k];
    }
    return s;
}

signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d %d", &l[i], &r[i], &tt[i]);
        ord[i] = i;
    }
    sort(ord + 1, ord + n + 1, cmp);
    tot = 0;
    for (i = 1; i <= n; i++) {
        int id = ord[i];
        int have = cntin(l[id], r[id]);
        int need = tt[id] - have;
        for (j = r[id]; j >= l[id] && need > 0; j--) {
            if (put[j] == 0) {
                put[j] = 1;
                tot++;
                need--;
            }
        }
    }
    printf("%d\n", tot);
    return 0;
}
