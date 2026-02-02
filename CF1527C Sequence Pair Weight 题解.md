# 题意简析

计算给定序列的所有字段权值和，权值定义为有相同数值的下标对数。

# 思路解析

首先考虑到枚举，一个长度为 $n$ 的序列，总共可以产生 $n^2$ 数量级的子序列，子序列的最长长度为 $n$，时间复杂度为 $O(n^3)$。

---

但我们想到，这其中的枚举肯定会有很多重复，所以考虑优化。

这里有一种 $O(n)$ 的做法，对于每个下标对 $(i,j)$，包含它的子段数量是 $i(n-j+1)$。为什么呢？因为它的左端点是 $[1,i]$，右端点是 $[j,n]$，左端点有 $i$ 种可能，右端点有 $n-j+1$ 种可能，根据~~我们小学二年级就学过的~~乘法原理，那么这个子段对答案的贡献就是 $i(n-j+1)$ 个它所拥有的相同数值下标对数。

对于每个数值的出现的下标的序列，我们令其为 $p$，大小为 $m$，那么我们的答案就是：

$$
\sum_{i=1}^{m-1} \sum_{j=i+1}^{m} p_i(n-p_j+1)
$$

这个东西弄不好还是 $O(n^2)$ 的，所以我们可以提取公因式，转化为：

$$

\sum_{i=1}^{m-1} [p_i \sum_{j=i+1}^{m}(n-p_j+1)]


$$

预处理后缀和处理即可。

# 代码实现

这里带 $\log$ 的原因是用了 `unordered_map`，如果实现的好的话是可以去的。

## 实现1：

```cpp

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int T, n, ans, a[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (cin >> T; T--;) {
        ans = 0;
        unordered_map<int, vector<int>> Pos;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            Pos[a[i]].push_back(i);
        }
        for (auto& [v, pos] : Pos) {
            int m = pos.size();
            if (m >= 2) {
                vector<int> suf(m, 0);
                suf[m - 1] = n - pos[m - 1] + 1;
                for (int i = m - 2; i >= 0; i--) {
                    suf[i] = suf[i + 1] + (n - pos[i] + 1);
                }
                for (int i = 0; i < m - 1; i++) {
                    ans += pos[i] * suf[i + 1];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

```

## 实现2

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, T;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (cin >> T; T--;) {
        cin >> n;
        unordered_map<int, int> suf;
        ans = 0;
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            ans += suf[x] * (n - i + 1);
            suf[x] += i;
        }
        cout << ans << '\n';
    }
    return 0;
}
```


# 后记
[双倍经验](https://www.luogu.com.cn/problem/B4453)