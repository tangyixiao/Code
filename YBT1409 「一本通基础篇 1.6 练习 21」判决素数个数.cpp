#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool np[N];
int x, y;

inline void input() {
    cin >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    for (int i = 2; i * i <= y; i++) {
        if (!np[i]) {
            for (int j = i * i; j <= y; j += i) {
                np[j] = 1;
            }
        }
    }
}

inline void solve() {
    int cnt = 0;
    for (int i = x; i <= y; i++) {
        if (i >= 2 && !np[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
