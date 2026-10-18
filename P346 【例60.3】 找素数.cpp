#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int a, b;
bool v[N];

inline void input() { cin >> a >> b; }

inline void solve() {
    for (int i = 2; i <= b; i++) {
        if (v[i]) {
            continue;
        }
        for (int j = i + i; j <= b; j += i) {
            v[j] = 1;
        }
        if (i >= a) {
            cout << i << "\n";
        }
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}