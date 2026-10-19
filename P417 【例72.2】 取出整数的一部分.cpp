#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

inline void input() {
    cin >> n >> k, s = to_string(n);
    return;
}

inline void solve() {
    int m = s.size(), p = abs(k);
    if (p > m) {
        cout << "Error\n";
        return;
    }
    string r = s;
    if (k > 0) {
        r = s.substr(0, p);
    } else if (k < 0) {
        r = s.substr(m - p);
    }
    cout << atoi(r.c_str()) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
