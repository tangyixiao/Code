#include <bits/stdc++.h>
using namespace std;

const int N = 2e1 + 5;

double p[N] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
int a[N];
double s;

inline void input() {
    for (int i = 1; i <= 10; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 1; i <= 10; i++) {
        s += p[i - 1] * a[i];
    }
    cout << fixed << setprecision(1) << s << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
