#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, score, x, cnt;

inline void input() {
    cin >> score >> n;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x > score) cnt++;
    }
    return;
}

inline void solve() {
    input();
    if (cnt * 10 < n) cout << "A\n";
    else if (cnt * 10 < n * 3) cout << "B\n";
    else if (cnt * 10 < n * 6) cout << "C\n";
    else if (cnt * 10 < n * 8) cout << "D\n";
    else cout << "E\n";
    return;
}

signed main() {
    solve();
    return 0;
}