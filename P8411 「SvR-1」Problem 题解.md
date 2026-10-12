# P8411 「SvR-1」Problem 题解

## 思路分析

做完一题后，高兴程度就是已经做过的题目里最小的 $a_i$。这个数只会保持不变或变小，不会再变大。

先看一个小例子。现在的高兴程度是 $10$，有两题都能做：$a_x=8$、$a_y=3$。假设 $z$ 是 $y$ 的后续题目，$a_z=12$。下面两种顺序都合法：

| 顺序 | 每步做完后的高兴程度 | 这几步的和 |
| --- | --- | ---: |
| $y,z,x$ | $3,3,3$ | $9$ |
| $x,y,z$ | $8,3,3$ | $14$ |

先做 $y$，高兴程度马上降到 $3$；之后做再多高分题，也回不到 $3$ 以上。先做 $x$ 则能先拿到 $8$，再做 $y$ 后两种顺序的高兴程度就一样了。

### 为什么每次取当前可做题里最大的 $a_i$

设当前能做的题里，$x$ 的 $a_x$ 最大。看一个最优顺序，找到其中的 $x$，把它挪到最前面；原来排在 $x$ 前面的题目整体往后挪一位。

新顺序仍然合法。$x$ 本来就能做；原来排在 $x$ 前面的题目不可能依赖 $x$，而它们之间的先后顺序也没有改变。

挪动后，第一步可能拿到更高的高兴程度。接着做原顺序的第一题时，因为 $a_x$ 不小于它的 $a_i$，高兴程度就和原顺序做完第一题时相同。再往后，挪动前后的高兴程度也依次相同。新顺序多出来的那一项，不低于原顺序最后做 $x$ 时的高兴程度，所以总和不会变小。

因此，总能把当前可做题里 $a_i$ 最大的题放到下一步。用大根堆维护这些题：先按题目要求做 $1$，把它的儿子放进堆；之后每次取出堆顶，更新当前最小值并把它的儿子放进堆。

代码用 `hd`、`nx` 两个数组保存树，用 `hp` 数组配合 `push_heap`、`pop_heap` 维护堆。所有工作数组都是全局定长数组。

## 复杂度

每道题最多进堆、出堆一次，时间复杂度 $O(n\log n)$，空间复杂度 $O(n)$。题目给出 $n\le10^7$，所以 `N = 1e7 + 5` 可以覆盖题目编号和堆中最多 $n-1$ 道待做题。答案不超过 $n(2^{32}-1)$，用 `long long` 保存即可。

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
