#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n;
double s, a[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    printf("%.4f\n", s / n);
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
