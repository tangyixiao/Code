#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 5;

char s[20][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}, b[M];

inline int pw(int a, int n) {
    int r = 1;
    for (; n; n >>= 1, a = a * a % 7) {
        if (n & 1) {
            r = r * a % 7;
        }
    }
    return r;
}

signed main() {
    long long a;
    cin >> a >> b;
    int t = 0;
    for (int i = 0; i < (int)strlen(b); i++) {
        t = (t * 10 + b[i] - '0') % 6;
    }
    cout << s[pw(a % 7, t)] << "\n";
    return 0;
}
