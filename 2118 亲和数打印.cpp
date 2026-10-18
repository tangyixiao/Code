#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, s[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        s[i] = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j) {
                continue;
            }
            if (j != i) {
                s[i] += j;
            }
            if (j * j != i) {
                s[i] += i / j;
            }
        }
        if (i == 1) {
            s[i] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i] > i && s[i] <= n && s[s[i]] == i) {
            cout << i << " " << s[i] << "\n";
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
