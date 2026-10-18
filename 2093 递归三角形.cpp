#include <bits/stdc++.h>
using namespace std;

const int N = 135;
int n, w[10];
char a[N][N];

inline void input() {
    cin >> n;
}

inline void draw(int x, int y, int k) {
    if (k == 1) {
        a[x][y] = '*';
        return;
    }
    draw(x, y, k - 1);
    draw(x, y + w[k - 1], k - 1);
    draw(x + w[k - 1], y, k - 1);
    return;
}

inline void solve() {
    w[1] = 1;
    for (int i = 2; i <= n; ++i) {
        w[i] = w[i - 1] * 2;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = ' ';
        }
    }
    draw(0, 0, n);
    for (int i = 0; i < w[n]; ++i) {
        int j = w[n] - 1;
        while (a[i][j] != '*') {
            --j;
        }
        for (int k = 0; k <= j; ++k) {
            cout << a[i][k];
        }
        cout << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
