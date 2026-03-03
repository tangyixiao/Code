
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
const int MAXA = 1000005;

int n, m;
int a[MAXN];
int last[MAXA];               // 每种颜色上一次出现的位置

struct Query {
    int l, r, id;
} q[MAXN];
int ans[MAXN];

int bit[MAXN];

inline int lowbit(int x) { return x & -x; }

void add(int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += lowbit(idx);
    }
}

int sum(int idx) {
    int res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= lowbit(idx);
    }
    return res;
}

bool cmp(const Query &x, const Query &y) {
    return x.r < y.r;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }

    sort(q, q + m, cmp);          // 按右端点排序

    int cur = 0;                  // 当前处理到第几个询问
    for (int i = 1; i <= n; ++i) {
        if (last[a[i]])           // 之前出现过，删除旧的标记
            add(last[a[i]], -1);
        add(i, 1);
        last[a[i]] = i;

        while (cur < m && q[cur].r == i) {
            ans[q[cur].id] = sum(q[cur].r) - sum(q[cur].l - 1);
            ++cur;
        }
    }

    for (int i = 0; i < m; ++i)
        printf("%d\n", ans[i]);

    return 0;
}
