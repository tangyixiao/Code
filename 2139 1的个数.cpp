#include <bits/stdc++.h>
using namespace std;

unsigned long long n;
int s;

inline void input() {
    cin >> n;
}

inline void solve() {
    while (n) {
        s += n & 1;
        n >>= 1;
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}