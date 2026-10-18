#include <bits/stdc++.h>
using namespace std;

int n, d[3] = {3, 5, 7}, t;

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 0; i < 3; i++) {
        if (n % d[i] == 0) {
            cout << d[i] << " ";
            t++;
        }
    }
    if (!t) {
        cout << "n";
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
