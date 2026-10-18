#include <bits/stdc++.h>
using namespace std;

const int N = 55;
long long a[N], b[N];
int x, y, z;

inline void input() {
    cin >> x >> y >> z;
    return;
}

inline void solve() {
    a[1] = 1;
    for (int i = 2; i <= z + 1; i++) {
        a[i] = a[i - 1] + (i > 2 ? b[i - 2] : 0), b[i] = y * (i > x ? a[i - x] : 0);
    }
    cout << a[z + 1] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
