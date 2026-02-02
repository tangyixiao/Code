#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef __int128 ll;

int T;
int n, m;
multiset<ll> s;
ll t[100010];
ll a[100010], b[100010], p[100010];
ll mx;

ll mul(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

ll exCRT() {
    ll A = 0, M = 1;  // 当前解 x ≡ A (mod M)
    
    for (int i = 1; i <= n; i++) {
        // 解方程: b[i] * x ≡ a[i] (mod p[i])
        // 即: b[i] * x + p[i] * y = a[i]
        
        ll x, y;
        ll g = exgcd(b[i], p[i], x, y);
        
        // 检查是否有解
        if (a[i] % g != 0) return -1;
        
        // 化为最简形式: (b[i]/g) * x ≡ a[i]/g (mod p[i]/g)
        ll p_i = p[i] / g;
        ll a_i = mul(a[i] / g, (x % p_i + p_i) % p_i, p_i);
        
        // 现在要合并方程: x ≡ a_i (mod p_i) 和 x ≡ A (mod M)
        // 即: x = a_i + p_i * k1 = A + M * k2
        // 所以: p_i * k1 - M * k2 = A - a_i
        
        ll k1, k2;
        ll g2 = exgcd(p_i, M, k1, k2);
        
        if ((A - a_i) % g2 != 0) return -1;
        
        // 得到新解
        ll lcm = M / g2 * p_i;
        ll diff = (A - a_i) / g2;
        k1 = (k1 % lcm * (diff % lcm)) % lcm;
        
        A = (a_i + mul(k1, p_i, lcm)) % lcm;
        A = (A + lcm) % lcm;
        M = lcm;
    }
    
    // 确保 x 满足最小攻击次数要求
    if (A < mx) {
        ll k = (mx - A + M - 1) / M;
        A += k * M;
    }
    
    return A;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    while (T--) {
        cin >> n >> m;
        
        for (int i = 1; i <= n; i++) {
            long long A;
            cin >> A;
            a[i] = A;
        }
        
        for (int i = 1; i <= n; i++) {
            long long P;
            cin >> P;
            p[i] = P;
        }
        
        for (int i = 1; i <= n; i++) {
            long long T;
            cin >> T;
            t[i] = T;
        }
        
        s.clear();
        for (int i = 1; i <= m; i++) {
            long long sword;
            cin >> sword;
            s.insert(sword);
        }
        
        mx = 0;
        for (int i = 1; i <= n; i++) {
            // 选择剑
            auto it = s.upper_bound(a[i]);
            if (it != s.begin()) {
                it--;
            }
            b[i] = *it;
            
            // 计算最小攻击次数
            ll need = (a[i] + b[i] - 1) / b[i];
            if (need > mx) mx = need;
            
            s.erase(it);
            s.insert(t[i]);
        }
        
        // 处理特殊情况
        bool special_case = false;
        for (int i = 1; i <= n; i++) {
            if (p[i] == 1) {
                // 如果模数为1，需要特殊处理
                // 方程变为 b[i]x ≡ a[i] (mod 1)，即 0 ≡ 0
                // 只需要满足 x >= ceil(a[i]/b[i])
                // 我们已经在mx中考虑了，所以可以忽略这个方程
            }
        }
        
        ll ans = exCRT();
        
        // 检查答案是否满足所有方程
        if (ans != -1) {
            for (int i = 1; i <= n; i++) {
                if (p[i] == 1) {
                    if ((ans * b[i]) % p[i] != a[i] % p[i]) {
                        ans = -1;
                        break;
                    }
                } else {
                    if ((ans * b[i]) % p[i] != a[i] % p[i]) {
                        ans = -1;
                        break;
                    }
                }
            }
        }
        
        if (ans == -1) {
            cout << -1 << '\n';
        } else {
            cout << (long long)ans << '\n';
        }
    }
    
    return 0;
}