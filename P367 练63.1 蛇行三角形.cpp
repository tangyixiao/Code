#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
int n;

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            int t = i + j - 1;
            cout << t * (t + 1) / 2 - i + 1 << (j == n - i + 1 ? "\n" : " ");
        }
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}