# 思路解析

怎么发现穿过原点？要么原数为正，操作后为负；要么原数为负，操作后为正。那么也就是说，操作前后异号就是穿过原点的充要条件。

观察到 $n$ 很小，考虑搜索或者状压。



## 搜索

用 DFS 枚举每一步的方向向左还是向右即可。

时间复杂度 $O(2^n)$

## 状压

用 $1$ 至 $2^n-1$ 的数维护向左或向右的状态，然后再 $O(n)$ 的时间算出答案。

时间复杂度 $O(n 2^n)$

# 代码实现

注意要开 `long long`。

## 状压

```cpp
int ans = 0;
for (int mask = 0; mask < (1 << n); mask++) {
    ll cur = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        ll nxt;
        if (mask & (1 << i)) nxt = cur + a[i];
        else nxt = cur - a[i];
        if (cur * nxt < 0) cnt++;
        cur = nxt;
    }
    ans = max(ans, cnt);
}
```

## 搜索

```cpp
const int N = 25;
int n, ans, a[N];

inline void dfs(int st, int u, int cnt) {
    if (st == n) {
        ans = max(ans, cnt);
        return;
    }
    int nxt = u + a[st];
    dfs(st + 1, nxt, cnt + (u * nxt < 0));

    nxt = u - a[st];
    dfs(st + 1, nxt, cnt + (u * nxt < 0));
    return;
}

inline void solve(int Task_Id) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] <<= 1;
    }
    dfs(0, 1, 0);
    cout << ans << '\n';
    return;
}
```