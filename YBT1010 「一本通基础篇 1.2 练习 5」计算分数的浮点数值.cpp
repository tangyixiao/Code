#include <bits/stdc++.h>
using namespace std;

int a, b;

inline void input() {
    cin >> a >> b;
}

inline void solve() {
    printf("%.9f\n", (double)a / b);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
