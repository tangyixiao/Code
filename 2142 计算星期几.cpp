#include <bits/stdc++.h>
using namespace std;

const char *w[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                   "Thursday", "Friday", "Saturday"};
int a, b;

inline void input() {
    cin >> a >> b;
}

inline void solve() {
    int s = 1, p = a % 7;
    for (int i = 1; i <= b; i++) {
        s = s * p % 7;
    }
    cout << w[s] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
