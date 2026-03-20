#include <bits/stdc++.h>
#define ONLINE_JUDGE
#define int long long
using namespace std;
const int mod = 998244353, N = 5e6 + 5;
int T, m, n, k, ans, fac[N], inv[N];
namespace Math {
inline int add(int A, int B) {
    return (A + B) % mod;
}
inline int sub(int A, int B) {
    return (A - B + mod) % mod;
}
inline int mul(int A, int B) {
    return (A * B) % mod;
}
inline int qpow(int A, int B) {
    int res = 1;
    while (B) {
        if (B & 1) {
            res = mul(res, A);
        }
        A = mul(A, A);
        B >>= 1;
    }
    return res;
}
inline void init(int R) {
    fac[0] = 1;
    for (int i = 1; i <= R; i++) {
        fac[i] = mul(fac[i - 1], i);
    }
    inv[R] = qpow(fac[R], mod - 2);
    for (int i = R - 1; i >= 0; i--) { // 传奇人物把这里写成i=R，直接覆盖掉了
        inv[i] = mul(inv[i + 1], i + 1);
    }
    return;
}
inline int combination(int A, int B) {
    if (B > A) {
        return 0;
    }
    if (B == 0) {
        return 1;
    }
    return mul(mul(fac[A], inv[B]), inv[A - B]);
}
} // namespace Math
using namespace Math;
inline void solve() {
    for (int x, y; T--;) {
        cin >> x >> y;
        ans ^= (combination(x, y));
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T >> n;
    init(n);
    solve();
    cout << ans << "\n";
    return 0;
}