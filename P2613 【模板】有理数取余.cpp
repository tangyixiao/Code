#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 19260817;
inline void read(int& x) {
    int f = 1;
    x = 0;
    char s = getchar();
    while (s > '9' || s < '0') {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (s <= '9' && s >= '0') {
        x = x * 10 % mod + (s - '0') % mod;
        s = getchar();
    }
    x = x % mod * f;
    return;
}
template <typename T>
inline T QuickPower(T Base, T Exponent, T Mod) {
    T ans = 1;
    while (Exponent) {
        if (Exponent & 1LL) {
            ans = ans * Base % Mod;
        }
        Base = Base * Base % Mod;
        Exponent >>= 1;
    }
    return ans % Mod;
}

int a, b;
signed main() {
    read(a), read(b);
    if (b) {
        printf("%lld", (QuickPower(b, mod - 2, mod) * a % mod + mod) % mod);
    } else {
        printf("Angry!");
    }
    return 0;
}