#include <bits/stdc++.h>
using namespace std;

const int N = 5 + 5;
int a[N][N], mx[N], mi[N], c[N];

inline void input() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= 5; i++) {
        mx[i] = mi[i] = 1;
        for (int j = 1; j <= 5; j++) {
            if (a[i][j] > a[i][mx[i]]) {
                mx[i] = j;
            }
            if (a[i][j] < a[i][mi[i]]) {
                mi[i] = j;
            }
        }
    }
    for (int j = 1; j <= 5; j++) {
        c[j] = 1;
        for (int i = 1; i <= 5; i++) {
            if (a[i][j] < a[c[j]][j]) {
                c[j] = i;
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (mx[i] == j && c[j] == i) {
                cout << i << " " << j << " " << a[i][j] << "\n";
                return;
            }
        }
    }
    cout << "not found\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}