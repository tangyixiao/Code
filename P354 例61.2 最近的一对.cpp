#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, i, j, best, bi, bf;
int a[N], id[N];
bool cmp(int x, int y) {
    if (a[x] != a[y]) {
        return a[x] < a[y];
    }
    return x < y;
}
signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    best = 1e9;
    bi = 1e9;
    bf = 1e9;
    for (i = 1; i <= n; i = j) {
        j = i;
        while (j + 1 <= n && a[id[j + 1]] == a[id[i]]) {
            j++;
        }
        if (j > i) {
            int fpos = id[i];
            int pre = id[i];
            for (int t = i + 1; t <= j; t++) {
                int cur = id[t];
                int dd = cur - pre;
                if (dd < best || (dd == best && fpos < bf)) {
                    best = dd;
                    bf = fpos;
                    bi = a[id[i]];
                }
                pre = cur;
            }
        }
        j++;
    }
    if (best >= 1e9) {
        printf("No\n");
        return 0;
    }
    printf("%d\n", bi);
    return 0;
}
