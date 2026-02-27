#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 21;
int n;
inline int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    bool flag = n & 1;
    cout << (qpow(3, n) - (flag ? 1 : -1) * 3) / 4;
    return 0;
}