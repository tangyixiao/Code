#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int pw[N], m;

inline void input() {
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * 10;
    }
    cin >> m;
    return;
}

inline void solve() {
    while (m--) {
        int w, k = 1;
        cin >> w;
        while (pw[k] <= w) {
            k++;
        }
        cout << w % pw[k - 1] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
