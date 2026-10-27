#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, i;
__int128 f[N];
void out(__int128 x) {
    if (x >= 10) {
        out(x / 10);
    }
    cout << (char)('0' + (int)(x % 10));
}
signed main() {
    cin >> n;
    f[0] = 1, f[1] = 1, f[2] = 2;
    for (i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
    out(f[n]);
    cout << "\n";
    return 0;
}
