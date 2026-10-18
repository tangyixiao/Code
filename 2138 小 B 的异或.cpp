#include <bits/stdc++.h>
using namespace std;

long long n;

inline void input() {
    cin >> n;
}

inline void solve() {
    cout << (n & 1) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}