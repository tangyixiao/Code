#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int, int> mp;
int a, b, p, ans;
int qpow(int a, int b, int p) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
}
int BSGS(int a, int b, int p) {
    if (a % p == b % p) {
        return 1;
    }
    if (a % p == 0 && b) {
        return -1;
    }
    int unit = (int)ceil(sqrt(p)), tmp = qpow(a, unit, p);
    for (int i = 0; i <= unit; i++) {
        mp[b] = i;
        b = (b * a) % p;
    }
    b = 1;
    for (int i = 1; i <= unit; i++) {
        b = (b * tmp) % p;
        if (mp[b]) {
            return i * unit - mp[b];
        }
    }
    return -1;
}
signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> p >> a >> b;
    int ans = BSGS(a, b, p);
    if (ans == -1) {
        cout << "no solution";
    } else {
        cout << ans;
    }
    return 0;
}