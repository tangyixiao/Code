#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
int T, k;
int d(int n) {
    if (n == 1) return 1;
    int cln = n;
    int res = 1;
    if (n % 2 == 0) {
        int power = 1, sum = 1; 
        while (n % 2 == 0) {
            power = (power * 2) % mod;
            sum = (sum + power) % mod;
            n /= 2;
        }
        res = (res * sum) % mod;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            int power = 1,sum = 1;
            while (n % i == 0) {
                power = (power * (i % mod)) % mod;
                sum = (sum + power) % mod;
                n /= i;
            }
            res = (res * sum) % mod;
        }
    }
    
    if (n > 1) {
        res = (res * (1 + (n % mod))) % mod;
    }
    
    return res;
}
inline void solve() {
    cin>>k;
    cout << (d(k) * d(k + 1)) % mod<<"\n";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}