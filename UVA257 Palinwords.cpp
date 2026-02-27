#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Mod1 = 1e9 + 7, Mod2 = 998244353;
const int Base1 = 131, Base2 = 31;
inline int Hash1(string s) {
    int ret = 0;
    for (char c : s) {
        ret = (ret * Base1 + c) % Mod1;
    }
    return ret;
}
inline int Hash2(string s) {
    int ret = 0;
    for (char c : s) {
        ret = (ret * Base2 + c) % Mod2;
    }
    return ret;
}
string s;
signed main() {
    while (cin >> s) {
    }
    return 0;
}