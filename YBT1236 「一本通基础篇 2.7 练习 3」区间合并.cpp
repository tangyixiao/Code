#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

pair<int, int> a[N];
int n;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    return;
}

inline void solve() {
    sort(a, a + n);
    int l = a[0].first, r = a[0].second;
    for (int i = 1; i < n; ++i) {
        if (a[i].first > r + 1) {
            cout << "no\n";
            return;
        }
        r = max(r, a[i].second);
    }
    cout << l << " " << r << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
