#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    input();
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
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