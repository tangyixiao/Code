#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;
int a[N], n, c;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) {
            a[c++] = x;
        }
    }
    sort(a, a + c);
    for (int i = 0; i < c; i++) {
        cout << a[i] << (i + 1 == c ? "\n" : ",");
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}