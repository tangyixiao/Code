#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e6 + 7;
int n, ans, j = 1;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++, j = (j << 1) % mod) {
        n -= i;
        ans = (ans + i * j) % mod;
    }
    cout << (ans + n * j) % mod;
    return 0;
}