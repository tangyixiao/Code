#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200005;
int n, m, B, k[N], cnt[N], to[N];

void upd(int x) {
    int blk = x / B * B, nxt = min(n, blk + B);
    for (int i = min(n - 1, x); i >= blk; --i) {
        int j = i + k[i];
        if (j >= n) cnt[i] = 1, to[i] = n;
        else if (j / B > i / B) cnt[i] = 1, to[i] = j;
        else cnt[i] = cnt[j] + 1, to[i] = to[j];
    }
}

int qry(int x) {
    int ans = 0;
    while (x < n) {
        ans += cnt[x];
        x = to[x];
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    B = (int)sqrt(n);
    for (int i = 0; i < n; ++i) scanf("%d", &k[i]);
    for (int i = n - 1; i >= 0; --i) {
        int j = i + k[i];
        if (j >= n) cnt[i] = 1, to[i] = n;
        else if (j / B > i / B) cnt[i] = 1, to[i] = j;
        else cnt[i] = cnt[j] + 1, to[i] = to[j];
    }
    scanf("%d", &m);
    while (m--) {
        int op, x, v;
        scanf("%d%d", &op, &x);
        if (op == 1) printf("%d\n", qry(x));
        else {
            scanf("%d", &v);
            k[x] = v;
            upd(x);
        }
    }
    return 0;
}