#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
unsigned long long a[N], mx;
int pos;

inline void input() {
    cin >> n;
    mx = 0, pos = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i], pos = i;
        }
    }
}

inline void solve() {
    cout << pos << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
