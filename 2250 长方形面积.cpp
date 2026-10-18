#include <bits/stdc++.h>
using namespace std;

int a;

inline void input() {
    cin >> a;
}

inline void solve() {
    int c = 0;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            c++;
        }
    }
    cout << c << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}