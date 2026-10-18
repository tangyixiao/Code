#include <bits/stdc++.h>
using namespace std;

int m, n;
string a, b, c;

inline void input() {
    cin >> m >> n, a = to_string(m), b = to_string(n), c = to_string(m * n);
    return;
}

inline void solve() {
    int q = b.size();
    cout << a << "\r\n";
    cout << b << "\r\n";
    for (int i = 0; i < q; i++) {
        cout << m * (b[q - 1 - i] - '0') << "\r\n";
    }
    cout << c << "\r\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}