#include <bits/stdc++.h>
using namespace std;

double t, r;
char a[1005], b[1005];

inline void input() {
    cin >> t >> a >> b;
    return;
}

inline void solve() {
    for (int i = 0; a[i]; i++) {
        if (a[i] == b[i]) {
            r++;
        }
    }
    cout << (r / strlen(a) >= t ? "yes" : "no") << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}