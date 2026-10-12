# P8411 「SvR-1」Problem 题解

## 思路分析

做完题目后的高兴程度，是已经完成题目中 $a_i$ 的最小值。每一步选出的题目会把这个最小值保持不变，或将它降低。

如果当前有多道题可以做，优先做其中 $a_i$ 最大的题目。设当前可做题中 $a_x$ 最大，而某个最优顺序的下一题是 $y$。在这个顺序里找到 $x$，把 $x$ 移到最前面，并将原来从开头到 $x$ 前面的题目整体后移一位。这样仍然合法：$x$ 原本就可做；其余题目保持相对次序，且 $x$ 不可能是它们的前置题，因为它们原本排在 $x$ 前面。

设开始这段顺序前的高兴程度为 $h$。新顺序第一步的贡献是 $\min(h,a_x)$；由于 $a_x\ge a_y$，后续每一步的高兴程度依次与原顺序前 $j-1$ 步相同，其中 $j$ 是 $x$ 原来的位置。新顺序的第一项不小于原顺序第 $j$ 项，因为原顺序第 $j$ 项还受此前所有题目的最小值限制。因此交换后总和不会变小。重复应用这个交换，就得到每一步都选当前可做题中 $a_i$ 最大者的最优方案。

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
    for (int i = 1; i < n; i++) {
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
