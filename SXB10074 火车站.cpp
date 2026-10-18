#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int a, n, m, x, up[N], cd[N];

inline void input() {
    cin >> a >> n >> m >> x;
    return;
}

signed main() {
    input();
    for (int b = 0; b <= 2e4; b++) {
        up[0] = up[1] = a, up[2] = b;
        cd[0] = cd[1] = cd[2] = a;
        for (int i = 3; i <= n - 1; i++) {
            up[i] = up[i - 1] + up[i - 2], cd[i] = cd[i - 1] + up[i - 2];
        }
        if (cd[n - 1] == m) {
            cout << (x == n ? 0 : cd[x]) << "\n";
            break;
        }
    }
    return 0;
}