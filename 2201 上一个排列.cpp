#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

inline void solve() {
    int i = n - 1;
    for (; i >= 1 && a[i] <= a[i + 1]; --i) {
    }
    if (i < 1) {
        cout << "ERROR\n";
        return;
    }
    int j = n;
    for (; a[j] >= a[i]; --j) {
    }
    swap(a[i], a[j]);
    reverse(a + i + 1, a + n + 1);
    for (int k = 1; k <= n; ++k) {
        cout << a[k] << (k == n ? "\n" : " ");
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}