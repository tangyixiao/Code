# P8411 「SvR-1」Problem 题解

## 思路分析

做完一道题后，高兴程度等于已经做过的题目中最小的 $a_i$。所以它只会保持不变或变小；一旦太早做了低 $a_i$ 的题，后面做高分题也补不回来。

看一个例子。当前高兴程度是 $10$，有两道题现在就能做：$a_x=8$、$a_y=3$。假设 $z$ 是 $y$ 的后续题，$a_z=12$。

| 顺序 | 每步做完后的高兴程度 | 总和 |
| --- | --- | ---: |
| $y,z,x$ | $3,3,3$ | $9$ |
| $x,y,z$ | $8,3,3$ | $14$ |

先做 $y$，高兴程度立刻降到 $3$，之后做 $z$ 或 $x$ 都不能让它回升。先做 $x$，则可以先得到 $8$；做完 $y$ 后，两种顺序的高兴程度才相同。

### 为什么每次选当前能做的题中 $a_i$ 最大的

设当前能做的题里，$x$ 的 $a_x$ 最大。取一个总和最大的合法做题顺序，把其中的 $x$ 移到最前面，并让原来排在 $x$ 前面的题依次后移。

新顺序仍然合法。$x$ 本来就能做；原来排在 $x$ 前面的题不能依赖 $x$，否则原顺序就不合法。它们彼此之间的顺序也没有改变。

再看高兴程度。把原顺序的第一题记成 $u$。它现在也能做，所以 $a_u\le a_x$。

做完 $u$ 后，高兴程度已经不超过 $a_u$，也就不超过 $a_x$。

因此，提前做过一次 $x$，不会改变做完 $u$ 时的最小值。后面每一步都包含 $u$，也不会被提前做的 $x$ 压得更低。

于是，新顺序从第二步开始的高兴程度，依次等于原顺序第一步、第二步……的高兴程度。

新顺序多出了最前面的 $x$，去掉了原来那一段最后的 $x$。前者的贡献是 $\min(h,a_x)$，其中 $h$ 是当前高兴程度；后者还要受中间那些题的最小值限制，只会更小或相同。

所以总和不会变小。每一步都能这样交换，就说明每次选当前能做的题里 $a_i$ 最大的，确实能得到最优答案。

实现时先按题目要求做题 $1$，再把它的儿子放入大根堆。之后每次取出堆顶，更新已经做过题目的最小 $a_i$，把这次做完的题的儿子加入堆。堆里始终是当前已经解锁、还没有做的题。

树用 `hd`、`nx` 存，堆用 `hp` 配合 `push_heap`、`pop_heap` 维护。

## 复杂度

每道题最多进堆、出堆一次，时间复杂度 $O(n\log n)$，空间复杂度 $O(n)$。

$n\le10^7$，所以数组开到 `N = 1e7 + 5`。答案不超过 $n(2^{32}-1)$，用 `long long` 即可。

## 代码

代码只列出模板末尾的 `namespace TANGYIXIAO` 部分。

```cpp
namespace TANGYIXIAO {
const int N = 1e7 + 5;
uint32_t a[N], sd;
int n, hd[N], nx[N], hp[N], hs;
long long mn, ans;

inline uint32_t rnd() {
    sd ^= sd << 13;
    sd ^= sd >> 17;
    sd ^= sd << 5;
    return sd;
}

inline bool cmp(int x, int y) {
    return a[x] < a[y];
}

inline void solve(int Task_Id) {
    cin >> n >> sd;
    for (int i = 1; i <= n; i++) {
        a[i] = rnd(), hd[i] = -1;
    }
    for (int i = 2; i <= n; i++) {
        int f = rnd() % (i - 1) + 1;
        nx[i] = hd[f], hd[f] = i;
    }
    hs = 0;
    for (int v = hd[1]; v != -1; v = nx[v]) {
        hp[hs++] = v;
        push_heap(hp, hp + hs, cmp);
    }
    mn = a[1], ans = mn;
    for (int i = 1; i < n; i++) {
        pop_heap(hp, hp + hs, cmp);
        int u = hp[--hs];
        mn = min(mn, (long long)a[u]);
        ans += mn;
        for (int v = hd[u]; v != -1; v = nx[v]) {
            hp[hs++] = v;
            push_heap(hp, hp + hs, cmp);
        }
    }
    cout << ans << "\n";
    return;
}
} // namespace TANGYIXIAO
```
