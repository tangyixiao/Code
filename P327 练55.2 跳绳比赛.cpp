#include <bits/stdc++.h>
using namespace std;
const int N = 5 + 5;
int a[N];

inline void input() {
    for (int i = 1; i <= 5; i++) {
        cin >> a[i];
    }
}

inline void solve() {
    sort(a + 1, a + 6, greater<int>());
    for (int i = 1; i <= 5; i++) {
        cout << a[i] << (i == 5 ? "\n" : " ");
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}