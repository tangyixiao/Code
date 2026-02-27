# 思路解析

由 $1$ 变成 $10$，长度多 $1$，$1$ 个数不变；$0$ 变成 $1$，长度不变，$1$ 个数多 $1$。

设 $len[i]$ 表示长度，$cnt[i]$ 表示 $1$ 的个数，可得：

$$
len[i] = len[i-1] + cnt[i-1]
$$

$$
cnt[i] = cnt[i-1] + len[i-1] - cnt[i-1]
$$

观察变化，可得：

$$
len[i]=len[i-1]+len[i-2]


$$

推得：

$$
cnt[i]=cnt[i-1]+cnt[i-2]
$$

根据序列产生原理，对大序列分解成小序列进而求解 这个东西和斐波那契很像，答案即为 $[1,b]$ 与 $[1,a-1]$ 的 $1$ 的个数之差，前缀和即可。

# 代码实现

```cpp

#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 100;
int len[N], ones[N];
void init() {
    len[0] = 1;
    len[1] = 2;
    ones[0] = 1;
    ones[1] = 1;
    for (int i = 2; i < N; i++) {
        len[i] = len[i - 1] + len[i - 2];
        ones[i] = ones[i - 1] + ones[i - 2];
    }
}
int count(int n, int x) {
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    if (n == 1) {
        if (x == 1)
            return 1;
        if (x == 2)
            return 1;
    }
    if (x <= len[n - 1]) {
        return count(n - 1, x);
    } else {
        return ones[n - 1] + count(n - 2, x - len[n - 1]);
    }
}
int calc(int x) {
    if (x == 0)
        return 0;
    int n = 0;
    while (len[n] < x)
        n++;
    return count(n, x);
}
main() {
    init();
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        int ans = calc(b) - calc(a - 1);
        cout << ans << endl;
    }
    return 0;
}
```
