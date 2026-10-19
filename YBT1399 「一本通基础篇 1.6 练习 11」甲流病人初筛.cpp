#include <bits/stdc++.h>
using namespace std;

int n;
string s;
double t;
int c, ans;

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        cin >> s >> t >> c;
        if (t >= 37.5 && c) {
            cout << s << "\n";
            ++ans;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}