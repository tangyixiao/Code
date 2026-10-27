#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i, j, hh, mm, t, ans, cnt, best;
int type[N], price[N], st[N], ord[N], ok2[N];

bool cmp(int a, int b) {
    if (st[a] != st[b]) {
        return st[a] < st[b];
    }
    return a < b;
}

signed main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d %d:%d", &type[i], &price[i], &hh, &mm);
        st[i] = hh * 60 + mm;
        ord[i] = i;
    }
    sort(ord + 1, ord + n + 1, cmp);
    ans = 0;
    for (i = 1; i <= n; i++) {
        int id = ord[i];
        if (type[id] == 0) {
            ans += price[id];
            continue;
        }
        int use = 0;
        for (j = 1; j <= n; j++) {
            int c = ord[j];
            if (!ok2[c] && type[c] == 0 && st[id] - st[c] >= 0 && st[id] - st[c] <= 45) {
                ok2[c] = 1;
                use = 1;
                break;
            }
        }
        if (!use) {
            ans += price[id];
        }
    }
    printf("%d\n", ans);
    return 0;
}
