#include <bits/stdc++.h>
using namespace std;

const int N = 4e1 + 5;

int n;
string s;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (; n; n >>= 3) {
        s = char('0' + (n & 7)) + s;
    }
    cout << s << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
