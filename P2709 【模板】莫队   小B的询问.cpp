#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAXN = 50005;
const int MAXK = 50005;

int n, m, k;
int a[MAXN];
int cnt[MAXK];
long long ans[MAXN];
int block;

struct Query {
    int l, r, id;
} q[MAXN];

bool cmp(const Query &x, const Query &y) {
    // 按左端点所在块排序，若相同则按右端点，利用奇偶性优化
    int xb = x.l / block, yb = y.l / block;
    if (xb != yb)
        return xb < yb;
    return (xb & 1) ? (x.r > y.r) : (x.r < y.r);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    block = (int)sqrt(n);
    sort(q, q + m, cmp);

    int curL = 1, curR = 0;
    long long curAns = 0;
    for (int i = 0; i < m; ++i) {
        int L = q[i].l, R = q[i].r;
        while (curL > L) {
            curL--;
            int x = a[curL];
            curAns += 2 * cnt[x] + 1;
            cnt[x]++;
        }
        while (curR < R) {
            curR++;
            int x = a[curR];
            curAns += 2 * cnt[x] + 1;
            cnt[x]++;
        }
        while (curL < L) {
            int x = a[curL];
            cnt[x]--;
            curAns -= 2 * cnt[x] + 1;
            curL++;
        }
        while (curR > R) {
            int x = a[curR];
            cnt[x]--;
            curAns -= 2 * cnt[x] + 1;
            curR--;
        }
        ans[q[i].id] = curAns;
    }

    for (int i = 0; i < m; ++i)
        printf("%lld\n", ans[i]);

    return 0;
}