#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, a[N];
set<int> s;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        if (s.count(a[i])) {
            continue;
        }
        s.insert(a[i]);
        cout << a[i] << " ";
    }
    cout << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}