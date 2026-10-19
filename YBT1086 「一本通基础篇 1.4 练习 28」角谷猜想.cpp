#include <bits/stdc++.h>
using namespace std;

long long n;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (; n != 1;) {
        if (n & 1) {
            cout << n << "*3+1=" << n * 3 + 1 << "\n";
            n = n * 3 + 1;
        } else {
            cout << n << "/2=" << n / 2 << "\n";
            n /= 2;
        }
    }
    cout << "End\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}