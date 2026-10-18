#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 0; i < 4 * n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    input();
    sort(a, a + 4 * n);
    for (int i = 0; i < 4 * n; i++) {
        if (i) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}