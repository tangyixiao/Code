#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N], k, s;

inline void input() {
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> k;
    return;
}

inline void solve() {
    for (int i = 0; i < N; i++) {
        if (a[i] - k <= 30) {
            s++;
        }
    }
    cout << s << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}