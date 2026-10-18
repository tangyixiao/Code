#include <bits/stdc++.h>
using namespace std;

int n;
unsigned long long k;

inline void input() {
    cin >> n >> k;
}

inline void solve() {
    for (int i = 0; i < n; ++i) {
        int x = int(((k >> (n - 1 - i)) & 1) ^ ((k >> (n - i)) & 1));
        cout << x;
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
