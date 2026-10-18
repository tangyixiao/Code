#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
    return;
}

inline int fib(int k) {
    if (k <= 2) {
        return k - 1;
    }
    return fib(k - 1) + fib(k - 2);
}

inline void solve() {
    cout << fib(n) << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}