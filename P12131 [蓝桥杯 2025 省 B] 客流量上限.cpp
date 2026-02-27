#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Math {
    const int Mod = 1e9 + 7;
    inline int Kuai_Cu_Mi(int Base, int Power) {
        int Ans = 1;
        while (Power) {
            if (Power & 1)
                Ans = (Ans * Base) % Mod;
            Base = (Base * Base) % Mod;
            Power >>= 1;
        }
        return Ans;
    }
}
signed main() {
    // cout << Math::Kuai_Cu_Mi(2, 1012);
    cout << 781448427;
    return 0;
}