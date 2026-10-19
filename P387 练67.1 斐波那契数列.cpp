#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5, P = 1500;
int f[P + 1];

inline void input() {
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= P; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % 1000;
    }
    return;
}

inline void solve() {
    int n;
    long long a;
    cin >> n;
    while (n--) {
        cin >> a;
        cout << f[a % P] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}