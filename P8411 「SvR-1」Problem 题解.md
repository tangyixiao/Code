# P8411 「SvR-1」Problem 题解

## 思路分析

做完题目后的高兴程度，是已经完成题目中 $a_i$ 的最小值。每一步选出的题目会把这个最小值保持不变，或将它降低。

如果当前有多道题可以做，优先做其中 $a_i$ 最大的题目。设此时有两道可做题 $x,y$，且 $a_x\ge a_y$。若某个方案先做 $y$，可以把 $x$ 提前到 $y$ 的位置：$x$ 的前置条件已经满足，而原来安排在 $y$ 之后的题目仍然合法。提前做 $x$ 不会让任何一步的高兴程度变低；等到原来做 $x$ 的位置再做 $y$ 后，最小值也与原方案相同。因此总能把最优方案的下一题换成当前可做题里 $a_i$ 最大的题。

用大根堆维护所有已经满足前置条件的题目。先做题目 $1$，随后每次取出堆顶并加入它的儿子。父亲编号小于儿子编号，所以按输入生成父亲关系后，用 `head`、`nxt` 数组保存树的邻接表即可。

题目值由 32 位无符号数生成，答案至多为 $n(2^{32}-1)$，使用 `long long` 足够。

## 复杂度

每道题至多进入和离开堆一次，时间复杂度 $O(n\log n)$，空间复杂度 $O(n)$。

## 代码

代码只列出模板末尾的 `namespace TANGYIXIAO` 部分。

```cpp
namespace TANGYIXIAO {
inline void solve(int Task_Id) {
    int n;
    uint32_t seed;
    cin >> n >> seed;
    vector<uint32_t> a(n + 1);
    vector<int> head(n + 1, -1), nxt(n + 1);
    for (int i = 1; i <= n; i++) {
        seed ^= seed << 13;
        seed ^= seed >> 17;
        seed ^= seed << 5;
        a[i] = seed;
    }
    for (int i = 2; i <= n; i++) {
        seed ^= seed << 13;
        seed ^= seed >> 17;
        seed ^= seed << 5;
        int fa = seed % (i - 1) + 1;
        nxt[i] = head[fa], head[fa] = i;
    }
    auto cmp = [&a](int x, int y) { return a[x] < a[y]; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int v = head[1]; v != -1; v = nxt[v]) {
        pq.push(v);
    }
    long long mn = a[1], ans = mn;
    for (int done = 1; done < n; done++) {
        int u = pq.top();
        pq.pop();
        mn = min(mn, (long long)a[u]);
        ans += mn;
        for (int v = head[u]; v != -1; v = nxt[v]) {
            pq.push(v);
        }
    }
    cout << ans << '\n';
    return;
}
} // namespace TANGYIXIAO
```
