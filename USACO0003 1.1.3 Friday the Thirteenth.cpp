#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int w[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, c[7];

inline bool leap(int a) {
    return (a % 4 == 0 && a % 100 != 0) || a % 400 == 0;
}

inline void input() {
    cin >> n;
}

inline void solve() {
    int y = 1900, dow = 0;
    for (int i = 0; i < n * 12; i++) {
        int m = i % 12 + 1;
        int len = w[m] + (m == 2 && leap(y));
        for (int d = 1; d <= len; d++) {
            if (d == 13) {
                c[dow]++;
            }
            dow = (dow + 1) % 7;
        }
        if (m == 12) {
            y++;
        }
    }
    for (int i = 0; i < 7; i++) {
        cout << c[(i + 5) % 7] << " \n"[i == 6];
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
