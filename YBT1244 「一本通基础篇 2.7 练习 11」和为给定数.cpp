#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long m, a[N];

inline void input() { cin >> n; }

inline void solve() {
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    sort(a, a + n);
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] + a[r] == m) {
            cout << a[l] << " " << a[r] << "\n";
            return;
        }
        if (a[l] + a[r] < m) {
            ++l;
        } else {
            --r;
        }
    }
    cout << "No\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}