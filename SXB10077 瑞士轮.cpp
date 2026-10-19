#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, r, q;
int s[N], w[N];
int id[N];

inline void input() {
    cin >> n >> r >> q;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        cin >> w[i];
        id[i] = i;
    }
}

inline void solve() {
    sort(id + 1, id + 2 * n + 1, [](int x, int y) {
        if (s[x] != s[y]) {
            return s[x] > s[y];
        }
        return x < y;
    });
    for (int i = 0; i < r; i++) {
        for (int j = 1; j <= n; j++) {
            int x = id[2 * j - 1], y = id[2 * j];
            int win = w[x] > w[y] ? x : y;
            s[win]++;
        }
        sort(id + 1, id + 2 * n + 1, [](int x, int y) {
            if (s[x] != s[y]) {
                return s[x] > s[y];
            }
            return x < y;
        });
    }
    cout << id[q] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
