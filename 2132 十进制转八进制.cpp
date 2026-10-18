#include <bits/stdc++.h>
using namespace std;

long long n;

inline void input() {
    cin >> n;
}

inline void solve() {
    string r;
    while (n) {
        r = char('0' + n % 8) + r;
        n /= 8;
    }
    if (r.size() == 0) {
        r = "0";
    }
    cout << r << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}