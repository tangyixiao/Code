#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int a[N], b[N], n;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
}

inline void solve() {
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cout << "NE" << "\n";
            return;
        }
    }
    cout << "DA" << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}