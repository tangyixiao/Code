#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, a[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 0; i < n; ++i) {
        a[i] = 1;
    }
    while (true) {
        for (int i = 0; i < n; ++i) {
            cout << a[i];
            if (i != n - 1) {
                cout << " ";
            }
        }
        cout << "\n";
        int i = n - 1;
        while (i >= 0 && a[i] == n) {
            --i;
        }
        if (i < 0) {
            break;
        }
        ++a[i];
        for (int j = i + 1; j < n; ++j) {
            a[j] = 1;
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
