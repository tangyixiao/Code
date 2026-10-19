#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, c;
bool t[N];

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!t[x]) {
            t[x] = true, c++;
        }
    }
    cout << c << "\n";
    for (int i = 1, j = 0; i < N; i++) {
        if (t[i]) {
            cout << i << (j == c - 1 ? "\n" : " "), j++;
        }
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}