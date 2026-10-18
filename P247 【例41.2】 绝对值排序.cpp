#include <bits/stdc++.h>
using namespace std;

int a[3];

bool cmp(int x, int y) {
    if (abs(x) != abs(y)) {
        return abs(x) < abs(y);
    }
    return x < y;
}

inline void input() {
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a, a + 3, cmp);
    for (int i = 0; i < 3; i++) {
        cout << a[i] << (i == 2 ? "\n" : " ");
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
