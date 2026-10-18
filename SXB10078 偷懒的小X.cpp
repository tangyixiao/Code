#include <bits/stdc++.h>
using namespace std;

const int N = 7e4 + 5;

int n;
int a[N];
int b[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}

inline void build(int j, int lo, int hi) {
    int ml = (hi - lo) / 2, mr = (hi - lo) - ml;
    b[j] = a[lo];
    if (ml > 0) {
        build(j * 2, hi - ml + 1, hi);
    }
    if (mr > 0) {
        build(j * 2 + 1, lo + 1, hi - ml);
    }
    return;
}

inline void solve() {
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \n"[i == n];
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
