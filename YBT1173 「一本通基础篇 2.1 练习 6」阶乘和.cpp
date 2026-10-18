#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, f[N], s[N];

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = 0; j < N; j++) {
            int v = f[j] * i + c;
            f[j] = v % 10, c = v / 10;
        }
        c = 0;
        for (int j = 0; j < N; j++) {
            int v = s[j] + f[j] + c;
            s[j] = v % 10, c = v / 10;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (s[i]) {
            for (; i >= 0; i--) {
                cout << s[i];
            }
            cout << "\n";
            return;
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}