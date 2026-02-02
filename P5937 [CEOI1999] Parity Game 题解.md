# 思路解析

老师讲的思路。

求区间的奇偶性，个数显然可以前缀和表示。一看到 $n \le 10^9 , m \le 5000$，考虑离散化（~~Hash~~）。 

我们小学一年级就学过，若两个数奇偶性相同，那么它们的和与差一定是偶数；若奇偶性相异，那么它们的和与差一定是奇数。

我们想到这个很像异或运算，所以这里用数组 $a$ 来表示奇偶性，则有：

$$
 a\{L-1,R\}= a[R] \oplus a[L]
$$

这个东西有传递性，所以我们用并查集存储这个区间关系：


- 如果根相同，判断 $L-1$ 相对于根节点的奇偶性与 $R$ 的是否与问题相同。

- 若根不同，说明可行，合并两根，$R$ 并到 $L-1$ 的根,两根建边 $a[\text{root}_b]=a[L-1] \oplus a[R] \oplus a\{L-1,R\}$。

这就是权值并查集的思路。

# 代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;
const int M = 5e3+5;
struct node {
    int x, y;
    bool f;  
}ques[M];
int n, m, idcnt,ans;
vector<int> fa,w;  
unordered_map<int, int> mp;
inline int gidx(int x) {
    if (mp.find(x) == mp.end()) {
        mp[x] = idcnt++;
    }
    return mp[x];
}
inline int find(int x) {
    if (fa[x] != x) {
        int rt = find(fa[x]);
        w[x] ^= w[fa[x]];  
        fa[x] = rt;
    }
    return fa[x];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("bullet.in", "r", stdin);
    //freopen("bullet.out", "w", stdout);
    cin >> n >> m;
    ans=m;
    for (int i = 0,x,y; i < m; i++) {
        string op;
        cin >> x >> y >> op;
        ques[i].x = x - 1,ques[i].y = y,ques[i].f = (op == "even");
        gidx(ques[i].x);
        gidx(ques[i].y);
    }

    int tiot = idcnt;
    fa.resize(tiot);
    w.resize(tiot, 0);
    for (int i = 0; i < tiot; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int l = gidx(ques[i].x),r = gidx(ques[i].y),rl = find(l),rr = find(r);
        
        if (rl == rr) {
            if ((w[l] == w[r])^ ques[i].f) {
                ans = i;  
                break;
            }
        } else {
            int nw = w[l] ^ w[r] ^ (!ques[i].f);
            fa[rl] = rr;
            w[rl] = nw;
        }
    }
    
    cout << ans;
    return 0;
}

```

