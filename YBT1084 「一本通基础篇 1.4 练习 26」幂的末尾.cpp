#include <bits/stdc++.h>
using namespace std;

inline int pw(int a, int b) {
    int r = 1;
    a %= 1000;
    for (; b; b >>= 1, a = a * a % 1000) {
        if (b & 1) {
            r = r * a % 1000;
        }
    }
    return r;
}

signed main() {
    long long a, b;
    cin >> a >> b;
    cout << setw(3) << setfill('0') << pw(a, b) << "\n";
    return 0;
}
