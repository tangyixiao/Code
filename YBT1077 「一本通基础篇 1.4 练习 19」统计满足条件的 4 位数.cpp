#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] % 10 - a[i] / 1000 - a[i] / 100 % 10 - a[i] / 10 % 10 > 0) {
            ++s;
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}