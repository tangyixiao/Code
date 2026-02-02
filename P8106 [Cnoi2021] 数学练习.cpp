#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P = 998244353;
int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) {
            (res *= x) %= P;
        }
        (x *= x) %= P;
        y >>= 1;
    }
    return res;
}
int C(int n, int m) {
    int a = 1, b = 1;
    for (int i = 1; i <= m; ++i) {
        (a *= i) %= P;
        (b *= n - i + 1) %= P;
    }
    return b * qpow(a, P - 2) % P;
}
int Lucas(int n, int m) {
    return !m ? 1 : C(n % P, m % P) * Lucas(n / P, m / P) % P;
}
signed main() {
    ios ::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    int res = qpow(2, n - 2);
    if (!(n & 1)) {
        (res -= Lucas(n - 2, n - 2 >> 1) - P) %= P;
    }
    cout << res << '\n';
    return 0;
}
