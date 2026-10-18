#include <bits/stdc++.h>
using namespace std;

double a, b;

inline void input() {
    cin >> a >> b;
}

inline void solve() {
    printf("%.2f\n", fmod(a, b));
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
