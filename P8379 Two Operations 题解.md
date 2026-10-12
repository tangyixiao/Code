# P8379 Two Operations 题解

## 思路分析

先只考虑一次 `Query`。

我们可以决定最后把大家合并进哪一组。设选的是第 $i$ 组，先把其他组合到一起，最后再整体合并进它。

记所有学生的糖果总数为 $C$，第 $i$ 组的糖果总数为 $s_i$，最多糖果数为 $mx_i$，总人数为 $n$。

最后一次合并时，其他组的学生先被清零，然后所有人都得到：

$$
\frac{C-s_i}{n}
$$

颗糖。

第 $i$ 组原来最多有 $mx_i$ 颗糖，所以最后的最大值就是：

$$
mx_i+\frac{C-s_i}{n}.
$$

比如样例里，一组有 $3,4$ 颗糖，另一组有 $5$ 颗糖。把第二组合并进第一组，三个人都增加 $5/3$，原来第一组的 $4$ 颗糖保留，最终最大值就是：

$$
4+\frac53=\frac{17}{3}.
$$

### 分几次合并会不会更好

不会。

无论怎么合并，总有一组从头到尾留到最后。它可以接收别的组，但不能被合并进别人，否则这一组就被删了。

设这一组是 $i$。它原来的学生从来没有被清零，所以 $mx_i$ 一直保留。

其余的 $C-s_i$ 颗糖，可能分几批合并进来。每一批分摊时，组内人数都不超过 $n$，所以组 $i$ 原来的每个人收到的糖果，不会少于把这一批直接除以 $n$。

加起来，至少增加 $(C-s_i)/n$。

因此，先把其他组合成一组、最后一次性合并进 $i$，就已经最好了。剩下只要选出最合适的 $i$。

### 怎么维护

把式子整理一下：

$$
mx_i+\frac{C-s_i}{n}
=\frac{C+(nmx_i-s_i)}n.
$$

$C,n$ 都不会改变，所以只要维护：

$$
\min_i(nmx_i-s_i).
$$

用 `set` 存每组的 $(nmx_i-s_i,i)$。带上组号，是因为不同组算出的值可能一样，删除时要能区分。

`Change` 只改组别，每个人的糖果数保持原值。清零、平均分糖，是 `Query` 计算答案时假设进行的操作，不会真的发生。

所以 `Change X Y` 时：

1. 把 $X,Y$ 原来的值从集合中删掉。
2. 糖果总数相加，最大值取两组最大值的较大者。
3. 删除 $X$，把更新后的 $Y$ 放回集合。

`Query` 时取集合中的最小值，代回上面的式子即可。最后除以 $n$，用模 $10^9+7$ 下的逆元处理。

## 复杂度

初始化 $O(n+k\log k)$，每次修改 $O(\log k)$，每次询问 $O(1)$，空间 $O(n+k)$。

## 代码

```cpp
namespace TANGYIXIAO {
const int N = 1e6 + 5, M = 1e1;
const long long MOD = 1e9 + 7;
int n, m, k, g[N], x, y;
long long s[N], mx[N], tot, iv, v;
char op[M];
set<pair<long long, int>> st;
inline long long pw(long long a, long long b) {
    long long r = 1;
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) {
            r = r * a % MOD;
        }
    }
    return r;
}
inline long long get(int x) { return 1LL * n * mx[x] - s[x]; }
inline void solve(int Task_Id) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v;
        s[g[i]] += v, mx[g[i]] = max(mx[g[i]], v), tot += v;
    }
    for (int i = 1; i <= k; i++) {
        st.emplace(get(i), i);
    }
    iv = pw(n, MOD - 2);
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op[0] == 'Q') {
            cout << (tot + st.begin()->first) % MOD * iv % MOD << "\n";
        } else {
            cin >> x >> y;
            if (x == y) {
                continue;
            }
            st.erase({get(x), x}), st.erase({get(y), y});
            s[y] += s[x], mx[y] = max(mx[y], mx[x]);
            s[x] = mx[x] = 0;
            st.emplace(get(y), y);
        }
    }
    return;
}
} // namespace TANGYIXIAO
```
