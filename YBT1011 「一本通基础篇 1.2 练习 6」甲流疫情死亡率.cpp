#include <bits/stdc++.h>
using namespace std;

int a, b;

inline void input() {
    cin >> a >> b;
}

inline void solve() {
    printf("%.3f%%\n", 100.0 * b / a);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
