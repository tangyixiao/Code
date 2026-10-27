#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int val[N], nxt[N], ord[N], ans[N];
bool hv[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int st, n;
    cin >> st >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        val[a] = b;
        nxt[a] = c;
        hv[a] = true;
    }
    int cnt = 0;
    for (int p = st; p != -1 && hv[p]; p = nxt[p]) {
        ord[cnt++] = p;
    }
    int l = 0, r = cnt - 1, t = 0;
    for (; l <= r;) {
        ans[t++] = ord[r--];
        if (l <= r) {
            ans[t++] = ord[l++];
        }
    }
    for (int i = 0; i < cnt; i++) {
        int p = ans[i];
        printf("%05d %d ", p, val[p]);
        if (i + 1 < cnt) {
            printf("%05d\n", ans[i + 1]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
