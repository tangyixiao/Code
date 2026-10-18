#include <bits/stdc++.h>
using namespace std;

const int N = 10;
double p[N] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65}, s;

inline void input() {
    return;
}

inline void solve() {
    for (int i = 0; i < N; i++) {
        int m;
        cin >> m, s += p[i] * m;
    }
    cout << fixed << setprecision(1) << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}