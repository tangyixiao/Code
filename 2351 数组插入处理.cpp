#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, a, b, p[N];

inline void input() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
}

inline void solve() {
    input();
    p[b - 1] = a;
    for (int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }
        cout << p[i];
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