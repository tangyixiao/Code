#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;

long long n;

inline void input() {
    cin >> n;
}

inline void solve() {
    if (n < 2 || (n % 2 == 0 && n != 2)) {
        cout << "NO\n";
        return;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}