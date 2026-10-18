#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
double f;

inline void input() {
    cin >> n;
}

inline void solve() {
    input();
    f = 0;
    for (int i = 1; i <= n; i++) {
        f = sqrt(i + f);
    }
    printf("%.2f\n", f);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}