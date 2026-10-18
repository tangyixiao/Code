#include <bits/stdc++.h>
using namespace std;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    if (n > 0) {
        cout << "positive\n";
    } else if (n == 0) {
        cout << "zero\n";
    } else {
        cout << "negative\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
