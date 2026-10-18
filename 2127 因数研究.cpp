#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
long long f[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) {
            f[j] += i;
        }
    }
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        s += f[i];
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
