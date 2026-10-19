#include <bits/stdc++.h>
using namespace std;

string s;
long long a, b;

inline void input() {
    cin >> s >> b;
    return;
}

inline void solve() {
    for (int i = 0; i < (int)s.size(); i++) {
        a = a * 2 + s[i] - '0';
    }
    cout << a * b << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
