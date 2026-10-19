#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N][3], c[N], b[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        c[i] = a[i][0], a[i][0] += a[i][1] + a[i][2], b[i] = i;
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        int j = i;
        while (j > 1 &&
               (a[b[j]][0] > a[b[j - 1]][0] ||
                (a[b[j]][0] == a[b[j - 1]][0] &&
                 (c[b[j]] > c[b[j - 1]] || (c[b[j]] == c[b[j - 1]] && b[j] < b[j - 1]))))) {
            swap(b[j], b[j - 1]);
            --j;
        }
    }
    for (int i = 1; i <= 5; ++i) {
        cout << b[i] << " " << a[b[i]][0] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
