#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int n;
bool b[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    unsigned int x = (unsigned int)n;
    for (int i = 0; i < 32; ++i) {
        b[i] = x & 1;
        x >>= 1;
    }
    for (int i = 0; i < 16; ++i) {
        if (b[i] != b[31 - i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}