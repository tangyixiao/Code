#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAXN = 50005;
const int MAXM = 50005;

int n, m;
int col[MAXN];
int cnt[MAXN];                    // 每种颜色的出现次数
long long ans1[MAXM], ans2[MAXM]; // 分子和分母
int block;

struct Query {
    int l, r, id;
} q[MAXM];

bool cmp(const Query &a, const Query &b) {
    int al = a.l / block, bl = b.l / block;
    if (al != bl)
        return al < bl;
    // 奇偶性优化
    return (al & 1) ? (a.r > b.r) : (a.r < b.r);
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &col[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    block = (int)sqrt(n);
    sort(q, q + m, cmp);

    int curL = 1, curR = 0;
    long long curAns = 0; // 当前分子（相同颜色对数）

    for (int i = 0; i < m; ++i) {
        int L = q[i].l, R = q[i].r;
        if (L == R) {
            ans1[q[i].id] = 0;
            ans2[q[i].id] = 1;
            continue;
        }
        while (curL > L) {
            curL--;
            int c = col[curL];
            curAns += cnt[c]; // 新增与当前相同颜色的配对
            cnt[c]++;
        }
        while (curR < R) {
            curR++;
            int c = col[curR];
            curAns += cnt[c];
            cnt[c]++;
        }
        while (curL < L) {
            int c = col[curL];
            cnt[c]--;
            curAns -= cnt[c];
            curL++;
        }
        while (curR > R) {
            int c = col[curR];
            cnt[c]--;
            curAns -= cnt[c];
            curR--;
        }
        long long total = (long long)(R - L + 1) * (R - L) / 2;
        long long g = gcd(curAns, total);
        ans1[q[i].id] = curAns / g;
        ans2[q[i].id] = total / g;
    }

    for (int i = 0; i < m; ++i) {
        printf("%lld/%lld\n", ans1[i], ans2[i]);
    }
    return 0;
}