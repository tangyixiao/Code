#include <bits/stdc++.h>
using namespace std;

const int N = 15 + 5;
const int W = 15 * 4 + 5;

char s[N], a[5][W];

inline void input() {
    cin >> s;
    int n = strlen(s), w = n * 4 + 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < w; j++) {
            a[i][j] = '.';
        }
        a[i][w] = '\0';
    }
    for (int k = 0; k < n; k++) {
        char c = (k % 3 == 2 ? '*' : '#'), b = k * 4;
        a[0][b + 2] = c, a[4][b + 2] = c;
        a[1][b + 1] = c, a[1][b + 3] = c;
        a[3][b + 1] = c, a[3][b + 3] = c;
        a[2][b] = c, a[2][b + 4] = c, a[2][b + 2] = s[k];
    }
}

inline void solve() {
    for (int i = 0; i < 5; i++) {
        cout << a[i] << "\n";
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