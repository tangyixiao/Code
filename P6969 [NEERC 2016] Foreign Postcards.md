# 题意简析

计算方向错误的明信片数量的期望值。

# 思路解析

因为期望的结算方式是在翻转之后，从前往后动态规划比较难处理。所以我们可以考虑逆向思维，从后往前处理。

自然地，$f(n+1) = 0$。

设 $f(i)$ 为 $[i, n]$ 期望值，则 $k$ 最大取到 $m = n - i + 1$，考虑状态转移。

- 若正确，错误数是 `W` 的数量。
- 若错误，错误数是 `C` 的数量。
  

那么有状态转移方程：

$$
f(i) = \frac{1}{m} \sum_{k=1}^{m} \left( g(i, k) + f(i+k) \right)
$$


其中 $g(i,k)$ 即为上方分类讨论结果。

发现这样子做还是太慢了，对于每一个 $f(i)$ 都要进行 $m$ 次计算，时间复杂度是 $O(n^2)$，显然不可行。

但是我们发现这个东西是可以进行优化的。首先是 `W` 和 `C` 的数量是可以有一个显然的前缀和来进行区间内计算的。比较难的地方在于，观察到这一个前缀和的计算也是可以被优化的，可以对前缀和计算后缀和，这样就可以 $O(1)$ 计算出 $g(i,k)$，而 $f(i)$ 显然也可以用相似的方法处理。
最终答案就是 $f(1)$。

时空复杂度 $O(n)$。

# 代码实现
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
double f, sf;
int n, p[N], sump[N];
string s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + (s[i - 1] == 'W');
    }
    for (int i = n; i >= 1; i--) {
        sump[i] = sump[i + 1] + p[i];
    }
    for (int i = n, m; i >= 1; i--) {
        m = n - i + 1;
        f = (s[i - 1] == 'C') ? (sump[i] - 1.0 * m * p[i - 1]) : (((1.0 * m * (m + 1) / 2.0 + 1.0 * m * p[i - 1] - sump[i])) + sf) / m;
        sf += f;
    }
    cout << fixed << setprecision(12) << f;
    return 0;
}
```