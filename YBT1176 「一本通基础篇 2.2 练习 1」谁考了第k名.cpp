#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int a[N], n, k;
double b[N];

inline void input() {
    cin >> n >> k;
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        int m = i;
        for (int j = i + 1; j <= n; j++) {
            if (b[j] > b[m]) {
                m = j;
            }
        }
        swap(b[i], b[m]), swap(a[i], a[m]);
    }
    cout << a[k] << " " << b[k] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}