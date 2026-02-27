# 题意简述

计算要经过的无交集的区间的跳跃距离之和。

# 思路解析

一个比较暴力的想法是枚举所有区间，然后计算跳跃距离之和，但是这样的时间复杂度是 $O(n^2k)$。

显然，有些区间可以看成一个区间，也就是把几个小区间合并成一个大的区间，把每个小区间的 $id$ 都赋予大区间的 $id$，类似于并查集的做法，这样时间复杂度看似很优，但是考虑一个极度稀疏的情况，有很多个小区间，时间复杂度可以达到 $O(nk)$，无法通过此题。

继承上面的思路，假如有一个测试数据是算第 $1$ 个大区间到第 $n$ 个大区间，和第 $n$ 个大区间到第 $1$ 个大区间的跳跃距离之和，那么我们显然没有必要一个个算区间中的每两者的的距离。

我们可以考虑**前缀和**。考虑将每个区间的 $dis$ 存入一个 $sum$ 数组里，把相同区间内的 $dis$ 增量设为 $0$，那么我们只需要 $O(1)$ 的时间复杂度进行区间查询。区间预处理是 $O(n)$ 的，总体时间复杂度 $O(\max(k,n))$，可以通过此题。




# 代码实现

模拟赛时的代码。

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, inf = 1e18;
struct node {
    int l, r, id;
    bool operator<(const node& A) const {
        return l < A.l;
    }
} a[N];

int n, k, ans, cnt, now, maxr = -inf, st[N], l[N], r[N], dis[N], sum[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("frjp.in", "r", stdin);
    //freopen("frjp.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i].l > maxr) {
            l[++cnt] = a[i].l;
            r[cnt] = a[i].r;
            maxr = a[i].r;
        } else {
            r[cnt] = max(r[cnt], (int)a[i].r);
            maxr = max(maxr, (int)a[i].r);
        }
        st[a[i].id] = cnt;
    }

    for (int i = 1; i < cnt; i++) {
        dis[i] = l[i + 1] - r[i];
        sum[i + 1] = sum[i] + dis[i];
    }
    now = st[1];
    for (int s; k--;) {
        cin >> s;
        if (st[s] != now) {
            ans += abs(sum[st[s]] - sum[now]);
            now = st[s];
        }
    }
    cout << ans;
    return 0;
}
```