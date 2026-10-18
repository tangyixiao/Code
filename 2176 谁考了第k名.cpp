#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, k, id[N];
double s[N];

inline void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> id[i] >> s[i];
    }
}

inline void solve() {
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (s[j] > s[i]) {
                swap(s[i], s[j]), swap(id[i], id[j]);
            }
        }
    }
    cout << id[k] << " " << s[k] << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}