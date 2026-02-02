#include <bits/stdc++.h>
#define int long long
//#define local
using namespace std;
const int mod = 1e9+7, phi = mod - 1;  
inline int modd(string num, int mod) {
    int res = 0;
    for (char c : num) {
        res = (res * 10 + (c - '0')) % mod;
    }
    return res;
}
inline int qpow(int a, int b) {
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef local
    freopen("pow.in", "r", stdin);
    freopen("pow.out", "w", stdout);
#endif 
    string a, b;
    cin >> a >> b;
    int moda=modd(a, mod);
    if(moda==0){
        cout<<0;
        return 0;
    }
    cout << qpow(moda,modd(b, phi));
    return 0;
}