#include <bits/stdc++.h>
using namespace std;

int x, y, z, q;

inline void input() {
    cin >> x >> y >> z >> q;
}

inline void solve() {
    int s = x * 2 + y * 5 + z * 3;
    if (q >= s) {
        cout << "Yes\n"
             << q - s << "\n";
    } else {
        cout << "No\n"
             << s - q << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}